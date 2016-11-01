#include "ImageProcessor.h"
#include <iostream>
void ImageProcessor::open_file(std::fstream& file ,const std::string input_path,bool write_flag = false)
{
	if (input_path == "") {
		std::cout << "File path is empty";
		exit(0);
	}
	file.open(input_path, (write_flag) ? std::fstream::out : std::fstream::in);
	if (!file.is_open())
	{
		std::cout << "Cannot open file, check file path" << std::endl;
		exit(0);
	}
}
void ImageProcessor::read_file(const std::string & input_path)
{
	open_file(in_file, input_path);
	for (size_t hp = 0; hp < h; hp++)
		for (size_t wp = 0; wp < w; wp++)
			in_file >> image_rep[hp][wp];
}

void ImageProcessor::write_output(const std::string & output_path)
{
	open_file(out_file, output_path, true);
	for (size_t hp = 0; hp < h; hp++) {
		for (size_t wp = 0; wp < w; wp++)
			out_file << image_proc_res[hp][wp];
		out_file << std::endl;
	}
}

void ImageProcessor::processing_algorith()
{
	const double min_sum = min_light_value * 5;
	for (size_t hp = 0; hp < h; hp++)
	{
		for (size_t wp = 0; wp < w; wp++)
		{
			if (hp == 0 || hp == h - 1) { image_proc_res[hp][wp] = '-'; continue; }		
			if (wp == 0 || wp == w - 1) { image_proc_res[hp][wp] = '|'; 	continue; }
			int current_sum = image_rep[hp][wp] + image_rep[hp - 1][wp] + image_rep[hp + 1][wp] + image_rep[hp][wp - 1] + image_rep[hp][wp + 1];
			image_proc_res[hp][wp] = (current_sum > min_sum) ? '*' : ' ';
		}
	}
}

ImageProcessor::ImageProcessor(const std::string & input_path)
{
	read_file(input_path);
}

void ImageProcessor::ProcessImage(const std::string & output)
{
	processing_algorith();
	write_output(output);
}

 

 