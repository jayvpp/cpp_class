#pragma once
#include "ImageHandlerBase.h"
#include "ImageCatalog.h"
#include "ImageProcessor.h"
#include "ImageSaver.h"
#include  <memory>

class ImageMozaicProcessor
{
private:
	std::unique_ptr<ImageCatalog> imageCatalog;
	std::unique_ptr<ImageHandlerBase> destintImage;
	std::unique_ptr<cv::Mat> finalImageCanvas;
	std::vector<ImageHandlerBase> originalImageSections;
	int wSize;

	void CropDestinationImageIntoSections() {
		for (int h = 0; h < destintImage->Height() - imageCatalog->ImageHeight(); h += imageCatalog->ImageHeight())
		{
			for (int w = 0; w < destintImage->Width() - imageCatalog->ImageWidth(); w += imageCatalog->ImageWidth())
			{
				ImageHandlerBase imageHandle = destintImage->CropImage(cv::Rect(w, h, imageCatalog->ImageWidth(), imageCatalog->ImageHeight()));
				originalImageSections.push_back(imageHandle);
			}
		}
	}
	void CreateCanva()
	{
		finalImageCanvas = std::make_unique<cv::Mat>(destintImage->Image().rows, destintImage->Image().cols, destintImage->Image().type());
		finalImageCanvas->setTo(0);
	}
public:
	ImageMozaicProcessor(std::vector<char*> smallImagePath, std::string destinationImage)
	{
		imageCatalog = std::make_unique<ImageCatalog>(smallImagePath);
		destintImage = std::make_unique<FileImageHandler>(destinationImage);
		wSize = destintImage->Width() / imageCatalog->ImageWidth();
		CreateCanva();
		CropDestinationImageIntoSections();
	}

	void ProcessImage(std::string destinationFileFullPath)
	{
		const double MAX_DISTANCE = 99999999;
		double bestDistance;

		cv::Mat finalImageCanvas(destintImage->Image().rows, destintImage->Image().cols, destintImage->Image().type());
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
				finalImageCanvas(cv::Rect(miw*currentBestImage->Image().cols, mih * currentBestImage->Image().rows,
					currentBestImage->Image().cols, currentBestImage->Image().rows))
				);
			if (i % 100 == 0)
				ImageSaver::save(destinationFileFullPath + "-InProgress-" + std::to_string(i) + ".jpg", finalImageCanvas);
		}
		ImageSaver::save(destinationFileFullPath + ".jpg", finalImageCanvas);
	}
};