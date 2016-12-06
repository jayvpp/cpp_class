// Final Project.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core//core.hpp"
#include "opencv2/opencv.hpp"
#include  <vector>
#include <fstream>
#include  <iostream>

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



class ImageHandle
{
class ImageDoesNotExistException {};
private:
	std::string path;

public:
	Mat image;

	ImageHandle(std::string path)
	{
		this->path = path;
		image = imread(path);		 
	}
	ImageHandle(const Mat& image)
	{
 
		path = "";
		this->image = image;
	}


	int Width() const { return image.size().width; }
	int Height() const { return image.size().height; }

	void DisplayPixels()
	{
		for (auto i = 0 ; i < image.rows ; i++)
		{
			for (auto j = 0 ; j < image.cols; j++)
			{
				auto px = GetPixelAtPosition(i, j);
				std::cout << "B: " << px.blue << "G: " << px.green << "R: " << px.red << std::endl;
			}
		}

	}
	PixelPacked GetPixelAtPosition(int row,int col)
	{
		PixelPacked pixel(image.at<Vec3b>(row, col)[0], image.at<Vec3b>(row, col)[1], image.at<Vec3b>(row, col)[2]);
		return pixel;
	}

	ImageHandle CropImage(const Rect& rectangle) const
	{
		Mat croppedImg = image(rectangle);
		return ImageHandle(croppedImg);
	}
 
};

class ImageSaver
{
public:
	static void save(std::string location, const Mat & image)
	{
		imwrite(location, image);
	}
};

class ImageResize
{
public:
	static void Resize(ImageHandle* image, int percent, std::string location)
	{
		Mat outputMat;
		resize(image->image, outputMat, Size(180, 150), 100, 100,CV_INTER_AREA);
	}
};


class ImageProcessor
{
private:
	ImageHandle* targetImage;
	ImageHandle* catalogImage;
public:
	ImageProcessor(ImageHandle* targetImage, ImageHandle* catalogImage)
	{
		this->targetImage = targetImage;
		this->catalogImage = catalogImage;
	}

	double CalculateDistance() const
	{
		double distance = 0;
		if (!EqualSize()) return 99999999;

		for (size_t h = 0; h < targetImage->Height(); h++)
		{
			for (size_t w = 0; w < targetImage->Width(); w++)
			{			 
				auto pixelTarget = targetImage->GetPixelAtPosition(h,w);
				auto pixelcatalog = catalogImage->GetPixelAtPosition(h, w);

				auto currentDistance = pixelTarget.CalculateDistance(pixelcatalog);
				distance += currentDistance;
			}
		}
		return distance / targetImage->image.size().area();
	}
private:
	bool EqualSize() const { 
		return targetImage->image.size().area() == catalogImage->image.size().area() && targetImage->Height() == catalogImage->Height(); }
};

 
class ImageCatalog
{
private:
	int width = -1;
	int height = -1;
	std::vector<ImageHandle> catalog;
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
				catalog.push_back(ImageHandle(line));
			myfile.close();
		}

		width = catalog.at(0).image.rows;
		height = catalog.at(0).image.cols;
	}
 
	const ImageHandle& ImageAt(int index) { return catalog.at(index); }
	int Size() const { return catalog.size(); }
	int ImageWidth() const { return width; }
	int ImageHeight() const { return height; }
	std::vector<ImageHandle>::iterator  begin() {return    catalog.begin(); }
	std::vector<ImageHandle>::iterator  end()   { return   catalog.end(); }
};


int main()
{
	ImageCatalog imageCatalog("C:\\images\\small");        //path to the catalog image folder, inside small you will have all the small images.

	ImageHandle destinationImage("C:\\pic\\jy.JPG");       //path of the destination image, the image you want to reproduce.

	auto wcount = destinationImage.Width() / imageCatalog.ImageWidth();

	std::vector<ImageHandle> OriginalImagesSplittledHandle;
	for (auto h = 0; h < destinationImage.Height()- imageCatalog.ImageHeight(); h += imageCatalog.ImageHeight())
	{
		for (auto w = 0; w < destinationImage.Width() - imageCatalog.ImageWidth(); w += imageCatalog.ImageWidth())
		{
			ImageHandle imageHandle = destinationImage.CropImage(Rect(w, h, imageCatalog.ImageWidth(), imageCatalog.ImageWidth()));
			OriginalImagesSplittledHandle.push_back(imageHandle);
		}	
	}

	Mat finalImageCanvas(destinationImage.image.rows, destinationImage.image.cols, destinationImage.image.type());
	finalImageCanvas.setTo(0);
 
	for (auto i = 0; i <= OriginalImagesSplittledHandle.size() - 5; i++)
	{
		auto mih = i / wcount;
		auto miw = i % wcount;

		ImageHandle first = OriginalImagesSplittledHandle.at(i);

		double bestDistance = 99999999;

		ImageHandle* currentBestImage = nullptr;
		for (auto& currentImage : imageCatalog)
		{
			ImageProcessor imageProcessor(&first, &currentImage);

			double currentDistance = imageProcessor.CalculateDistance();
			if (currentDistance < bestDistance)
			{
				bestDistance = currentDistance;
				currentBestImage = &currentImage;
			}
		}


		currentBestImage->image.copyTo(finalImageCanvas(Rect(miw*currentBestImage->image.cols, mih * currentBestImage->image.rows, currentBestImage->image.cols, currentBestImage->image.rows)));

		//just to save image in process, remove it later
		if (i % 100 == 0)
			ImageSaver::save("C:\\pic\\processImg" + std::to_string(i) + ".jpg", finalImageCanvas);
		
	}
	ImageSaver::save("C:\\pic\\jyilenafinal.jpg", finalImageCanvas);
	return 0;
}