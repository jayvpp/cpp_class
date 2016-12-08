#pragma once
#include "ImageHandlerBase.h"

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
				auto pixelTarget = targetImage->GetPixelAtPosition(h, w);
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