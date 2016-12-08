#pragma once
#include "ImageHandlerBase.h"
#include <string>


class FileImageHandler : public ImageHandlerBase
{

	class ImageDoesNotExistException {};
private:
	std::string path;
public:
	FileImageHandler(std::string path) : path(path) { image = cv::imread(path); }
};