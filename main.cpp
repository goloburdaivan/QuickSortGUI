#include<iostream>
#include<string>
#include<cassert>
#include<iomanip>

#include "util.h"
#include "quicksort.h"
#include "filemanager.h"
#include "GraphicsManager.h"

int main(int argc, char** argv) {
	std::string filename;

	if (!read_filename(argc, argv, filename)) {
		std::cout << "[ERROR] No filename." << std::endl;
		std::cout << "To see usage use SortingAlgos --help" << std::endl;
		return 0;
	}

	try {
		FileManager fm(filename);
		fm.write_data();
		GraphicsManager gm(100);
		gm.build_graph(MODE::BEST);
	}
	catch (FileManager::FileNotFoundException& exception) {
		std::cout << exception.message();
	}

	return 0;
}