#pragma once
#include <string>
#include <fstream>

class ImageProcessor
{
private:
	static const int h = 20;
	static const int w = 20;
	const double min_light_value = 6;

	std::fstream in_file;
	std::fstream out_file;

	int  image_rep[h][w];
	char image_proc_res[h][w];

	void open_file(std::fstream& file, const std::string input_path, bool write_flag);
	void read_file(const std::string & input_path);
	void write_output(const std::string& output_path);

	void processing_algorith();

public:
   
	ImageProcessor(const std::string& input_path);
	void ProcessImage(const std::string& output);
	
};