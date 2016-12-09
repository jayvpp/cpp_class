// Final Project.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include "opencv2/opencv.hpp"

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "FileImageHandler.h"
#include "ImageCatalog.h"
#include "ImageHandlerBase.h"
#include "ImageMozaicProcessor.h"
#include "ImageProcessor.h"
#include "ImageSaver.h"
#include "InMemoryImageHandler.h"
#include "PixelPacket.h"

int main()
{

	std::cout << "Crap:" << std::endl;

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
  
