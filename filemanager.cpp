#include "util.h"
#include "quicksort.h"
#include "filemanager.h"
#include<fstream>

FileManager::FileManager(std::string filename) : _filename(filename) {
	std::string default_path = DEFAULT_PATH;
	std::ifstream in(default_path + filename, std::ios::binary);

	if (!in.is_open()) {
		throw FileNotFoundException();
	}

	size_t size;
	in >> size;
	_size = size;

	_array_1 = std::make_unique<int[]>(size);
	_array_2 = std::make_unique<int[]>(size);
	_array_3 = std::make_unique<int[]>(size);
	size_t index = 0;
	int element;

	while (!in.eof()) {
		in >> element;
		_array_1[index] = element;
		_array_2[index] = element;
		_array_3[index] = element;
		index++;
	}

	in.close();
}

void FileManager::write_data() {

	std::string output_filename = _filename.replace(0, 5, "output");
	std::cout << "Output file: " << output_filename << std::endl;
	std::ofstream out("./examples/" + output_filename, std::ios::binary);
	if (!out.is_open()) throw FileNotFoundException();
	int default_comp = 0, median_comp = 0, three_p_comparasions = 0, temp = 0;
	
	quick_sort(_array_1.get(), 0, _size - 1, default_comp, temp);
	temp = 0;
	median3_quick_sort(_array_2.get(), 0, _size - 1, median_comp, temp);
	temp = 0;
	three_pivot_quick_sort(_array_3.get(), 0, _size - 1, three_p_comparasions, temp);
	temp = 0;

	out << default_comp << " " << median_comp << " " << three_p_comparasions;

	out.close();

	std::cout << "Data was added to the file." << std::endl;
}

