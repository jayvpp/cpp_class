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
		//fix this
		path = "";
		this->image = image;
	}


	int Width() const { return image.size().width; }
	int Height() const { return image.size().height; }

	void DisplayPixels()
	{
		for (int i = 0 ; i < image.rows ; i++)
		{
			for (int j = 0 ; j < image.cols; j++)
			{
				PixelPacked px = GetPixelAtPosition(i, j);
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
	static void save(ImageHandle * image, std::string location) 
	{
		//check that path is valid
		imwrite(location, image->image);
	}
};

class ImageResize
{
public:
	static void Resize(ImageHandle* image, int percent, std::string location)
	{
		Mat outputMat;
		resize(image->image, outputMat, Size(180, 150), 100, 100,CV_INTER_AREA);

		namedWindow("Cropped", CV_WINDOW_FREERATIO);
		imshow("Cropped", outputMat);

		
		//waitKey(0);
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
		int nomatch = 0;
		double distance = 0;
		if (!EqualSize()) return 99999999;

		for (size_t h = 0; h < targetImage->Height(); h++)
		{
			for (size_t w = 0; w < targetImage->Width(); w++)
			{
				 
				PixelPacked pixelTarget = targetImage->GetPixelAtPosition(h,w);
				PixelPacked pixelcatalog = catalogImage->GetPixelAtPosition(h, w);

				double current_dist = pixelTarget.CalculateDistance(pixelcatalog);
				if (current_dist != 0) {
					//std::cout << h << " - " << w << std::endl;
					//nomatch++;
				}
				else
				{
					//std::cout << h << " - " << w << std::endl;
				}
				distance += current_dist;
			}
		}
		double averageDistance = distance / targetImage->image.size().area();
		
		return averageDistance;

	}
private:
	bool EqualSize() const { 
		return targetImage->image.size().area() == catalogImage->image.size().area() && targetImage->Height() == catalogImage->Height(); }
};

 
class ImageCatalog
{
public:
	std::vector<ImageHandle> catalog;

	void LoadImageCatalog(std::string path)
	{
		std::ifstream myfile;
		myfile.open("C:\\pic\\pic.txt");
		std::string line;
		if (myfile.is_open())
		{
			while (std::getline(myfile, line))
				catalog.push_back(ImageHandle(line));
			myfile.close();
		}
	}
};


int main()
{
	ImageCatalog imageCatalog;
	imageCatalog.LoadImageCatalog("C:\\images\\small");

	ImageHandle m1("C:\\images\\small\\fotos (1081).JPG");

	ImageHandle big("C:\\pic\\jy.JPG");

	int wcount = big.Width() / m1.Width();
	int hcount = big.Height() / m1.Height();

	std::vector<ImageHandle> OriginalImagesSplittledHandle;
	for (int h = 0; h < big.Height()- m1.Height(); h += m1.Height())
	{
		for (int w = 0; w < big.Width() - m1.Width(); w += m1.Width())
		{
			ImageHandle imageHandle = big.CropImage(Rect(w, h, m1.Width(), m1.Height()));
			OriginalImagesSplittledHandle.push_back(imageHandle);
	 
		}	
	}

 

	Mat imgPanel(big.image.rows, big.image.cols, big.image.type());
	imgPanel.setTo(0);
 
	for (int i = 0; i <= OriginalImagesSplittledHandle.size() - 5; i++)
	{
		int mih = i / wcount;
		int miw = i % wcount;

		ImageHandle first = OriginalImagesSplittledHandle.at(i);


		double bestDistance = 99999999;
		int counter = -1;
		ImageHandle* best = nullptr;
		for (auto& currentImage : imageCatalog.catalog)
		{
			counter++;

			ImageProcessor ip(&first, &currentImage);


			double distance = ip.CalculateDistance();
			if (distance < bestDistance)
			{
				bestDistance = distance;
				best = &currentImage;
			}
		}


		best->image.copyTo(imgPanel(Rect(miw*best->image.cols, mih * best->image.rows, best->image.cols, best->image.rows)));

		if (i % 100 == 0)
		{
			imwrite("C:\\pic\\processImg" + std::to_string(i) + ".jpg", imgPanel);
		}
	}
           	imwrite("C:\\pic\\jyilenafinal.jpg",imgPanel);

	return 0;
}

