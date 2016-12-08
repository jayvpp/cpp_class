#pragma once
#include "ImageHandlerBase.h"


class InMemoryImageHandler : public ImageHandlerBase
{
public:
	InMemoryImageHandler(cv::Mat image)
	{
		this->image = image;
	}
	int Width() const { return image.size().width; }
	int Height() const { return image.size().height; }
};