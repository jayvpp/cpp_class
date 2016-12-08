#pragma once
#include "ImageHandlerBase.h"
#include <string>

class ImageSaver
{
public:
	static void save(std::string location, cv::Mat image)
	{
		imwrite(location, image);
	}
};