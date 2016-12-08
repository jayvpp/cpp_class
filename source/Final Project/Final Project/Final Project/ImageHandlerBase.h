#pragma once
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\core\\core.hpp"
#include "opencv2\opencv.hpp"
#include "PixelPacket.h"

class ImageHandlerBase
{
protected:
	cv::Mat image;
public:

	ImageHandlerBase() {}
	ImageHandlerBase(cv::Mat mat) { this->image = mat; }

	int Width() const { return image.size().width; }
	int Height() const { return image.size().height; }

	cv::Mat Image() const {
		return image;
	}

	PixelPacked GetPixelAtPosition(int row, int col)
	{
		PixelPacked pixel(image.at<cv::Vec3b>(row, col)[0], image.at<cv::Vec3b>(row, col)[1], image.at<cv::Vec3b>(row, col)[2]);
		return pixel;
	}

	ImageHandlerBase CropImage(cv::Rect rectangle) const
	{
		cv::Mat croppedImg = image(rectangle);
		return ImageHandlerBase(croppedImg);
	}
};