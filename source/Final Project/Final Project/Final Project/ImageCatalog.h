#pragma once
#include "FileImageHandler.h"
#include "ImageHandlerBase.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class ImageCatalog
{
private:
	int width;
	int height;
	std::vector<ImageHandlerBase> catalog;
public:
	ImageCatalog(std::vector<char*> catalogImagePath)
	{
		//this need to be replace with the function to detect files in folder.
	 

		for (auto& file : catalogImagePath)
			catalog.push_back(FileImageHandler(std::string(file)));
	 

		width = catalog.at(0).Image().cols;
		height = catalog.at(0).Image().rows;
	}

	const ImageHandlerBase& ImageAt(int index) { return catalog.at(index); }
	int Size() const { return catalog.size(); }
	int ImageWidth() const { return width; }
	int ImageHeight() const { return height; }
	std::vector<ImageHandlerBase>::iterator  begin() { return    catalog.begin(); }
	std::vector<ImageHandlerBase>::iterator  end() { return   catalog.end(); }
};