// Final Project.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

using namespace cv;
typedef unsigned char byte;

class PixelPacked
{
public:
	byte blue;
	byte green;
	byte red;

	PixelPacked(byte b, byte g, byte r) : blue{ b }, green{ g }, red{ r } {};
	double CalculateDistance(const PixelPacked& pixelPacket)const
	{
		byte dGreen = abs(green - pixelPacket.green);
		byte dBlue = abs(blue - pixelPacket.blue);
		byte dRed = abs(red - pixelPacket.red);

		return sqrt(pow(dGreen, 2) + pow(dBlue, 2) + pow(dRed, 2));
	}
};

class ImageHandlerBase
{
protected:
	Mat image;
public:
 
	ImageHandlerBase(){}
	ImageHandlerBase(Mat mat) { this->image = mat; }

	int Width() const { return image.size().width; }
	int Height() const { return image.size().height; }
	
	Mat Image() const {
		return image;
	}

	PixelPacked GetPixelAtPosition(int row, int col)
	{
		PixelPacked pixel(image.at<Vec3b>(row, col)[0], image.at<Vec3b>(row, col)[1], image.at<Vec3b>(row, col)[2]);
		return pixel;
	}

	ImageHandlerBase CropImage(Rect rectangle) const
	{
		Mat croppedImg = image(rectangle);
		return ImageHandlerBase(croppedImg);
	}
};


class InMemoryImageHandler : public ImageHandlerBase
{
public:
	InMemoryImageHandler(Mat image)
	{
		this->image = image;
	}
};

class FileImageHandler : public ImageHandlerBase
{
	class ImageDoesNotExistException {};
private:
	std::string path;
public:
	FileImageHandler(std::string path) : path(path) { image = imread(path); }
};

class ImageSaver
{
public:
	static void save(std::string location, Mat  image)
	{
		imwrite(location, image);
	}
};

class ImageResize
{
public:
	static void Resize(InMemoryImageHandler* image, int percent, std::string location)
	{
		Mat outputMat;
		resize(image->Image(), outputMat, Size(180, 150), 100, 100,CV_INTER_AREA);
	}
};


class ImageProcessor
{
private:
	ImageHandlerBase * targetImage;
	ImageHandlerBase* catalogImage;
public:
	ImageProcessor(ImageHandlerBase* targetImage, ImageHandlerBase* catalogImage)
	{
		this->targetImage = targetImage;
		this->catalogImage = catalogImage;
	}

	double CalculateDistance() const
	{
		double distance = 0;
		if (!EqualSize()) return 99999999;

		for (int h = 0; h < targetImage->Height(); h++)
		{
			for (int w = 0; w < targetImage->Width(); w++)
			{			 
				auto pixelTarget = targetImage->GetPixelAtPosition(h,w);
				auto pixelcatalog = catalogImage->GetPixelAtPosition(h, w);

				auto currentDistance = pixelTarget.CalculateDistance(pixelcatalog);
				distance += currentDistance;
			}
		}
		return distance / targetImage->Image().size().area();
			 
	}
private:
	bool EqualSize() const 
	{ 
		return targetImage->Image().size().area() == catalogImage->Image().size().area() && targetImage->Height() == catalogImage->Height(); 
	}
};


 
class ImageCatalog
{
private:
	int width;
	int height;
	std::vector<ImageHandlerBase> catalog;
public:
	ImageCatalog(std::string catalogPath)
	{
		//this need to be replace with the function to detect files in folder.
		std::ifstream myfile;
		myfile.open("C:\\pic\\pic.txt");
		std::string line;
		if (myfile.is_open())
		{
			while (std::getline(myfile, line))
				catalog.push_back(FileImageHandler(line));
			myfile.close();
		}

		width = catalog.at(0).Image().cols;
		height = catalog.at(0).Image().rows;
	}
 
	const ImageHandlerBase& ImageAt(int index) { return catalog.at(index); }
	int Size() const { return catalog.size(); }
	int ImageWidth() const { return width; }
	int ImageHeight() const { return height; }
	std::vector<ImageHandlerBase>::iterator  begin() {return    catalog.begin(); }
	std::vector<ImageHandlerBase>::iterator  end()   { return   catalog.end(); }
};

class ImageMozaicProcessor
{
private:
	std::unique_ptr<ImageCatalog> imageCatalog;
	std::unique_ptr<ImageHandlerBase> destintImage;
	std::unique_ptr<Mat> finalImageCanvas;
	std::vector<ImageHandlerBase> originalImageSections;
	int wSize;

	void CropDestinationImageIntoSections() {
		for (int h = 0; h < destintImage->Height() - imageCatalog->ImageHeight(); h += imageCatalog->ImageHeight())
		{
			for (int w = 0; w < destintImage->Width() - imageCatalog->ImageWidth(); w += imageCatalog->ImageWidth())
			{
				ImageHandlerBase imageHandle = destintImage->CropImage(Rect(w, h, imageCatalog->ImageWidth(), imageCatalog->ImageHeight()));
				originalImageSections.push_back(imageHandle);
			}
		}
	}
	void CreateCanva()
	{
		finalImageCanvas = std::make_unique<Mat>(destintImage->Image().rows, destintImage->Image().cols, destintImage->Image().type());
		finalImageCanvas->setTo(0);
	}
public:
	ImageMozaicProcessor(std::string imageCatalogFolderPath, std::string destinationImage)
	{
		imageCatalog = std::make_unique<ImageCatalog>(imageCatalogFolderPath);
		destintImage = std::make_unique<FileImageHandler>(destinationImage);
		wSize = destintImage->Width() / imageCatalog->ImageWidth();
		CreateCanva();
		CropDestinationImageIntoSections();
	}

	void ProcessImage(std::string destinationFileFullPath)
	{
		const double MAX_DISTANCE = 99999999;
		double bestDistance;
		
		Mat finalImageCanvas(destintImage->Image().rows, destintImage->Image().cols, destintImage->Image().type());
		finalImageCanvas.setTo(0);

		for (auto i = 0; i < originalImageSections.size(); i++)
		{
			auto mih = i / wSize;
			auto miw = i % wSize;

			ImageHandlerBase first = originalImageSections.at(i);

			bestDistance = MAX_DISTANCE;

			ImageHandlerBase* currentBestImage = nullptr;
			for (auto& currentImage : *imageCatalog)
			{
				ImageProcessor imageProcessor(&first, &currentImage);

				double currentDistance = imageProcessor.CalculateDistance();
				if (currentDistance < bestDistance)
				{
					bestDistance = currentDistance;
					currentBestImage = &currentImage;
				}
			}
			currentBestImage->Image().copyTo(
											finalImageCanvas(Rect(miw*currentBestImage->Image().cols, mih * currentBestImage->Image().rows,
											currentBestImage->Image().cols, currentBestImage->Image().rows))
											);
			if (i % 100 == 0)
				ImageSaver::save("C:\\pic\\InProcess" + std::to_string(i) + ".jpg", finalImageCanvas);
		}
		ImageSaver::save(destinationFileFullPath, finalImageCanvas);
	}
};


int main()
{
	std::string smallImagePath;
	std::string bigImagePath;
	std::string outputPath;
	std::cout << "Enter Small Gallery Path:" << std::endl;
	std::cin >> smallImagePath;

	std::cout << "Enter Big Image Path:" << std::endl;
	std::cin >> bigImagePath;

	std::cout << "Enter Destination Path:" << std::endl;
	std::cin >> outputPath;

	ImageMozaicProcessor p(smallImagePath, bigImagePath);
	p.ProcessImage("outputPath");

	return 0;
}
  
