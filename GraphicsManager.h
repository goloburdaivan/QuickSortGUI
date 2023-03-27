#pragma
#include<memory>
#include<functional>
#include<iostream>
#include<vector>
#include "filemanager.h"
#include "util.h"

enum MODE {
	WORST,
	BEST,
	AVARAGE
};

class GraphicsManager {
private:

	const std::vector<std::function<std::unique_ptr<int[]>(size_t)>> _builders {
		generate_worst_array, generate_best_array, generate_avarage_array
	};
	std::unique_ptr<int[]> _q_sort_comp_array;
	std::unique_ptr<int[]> _median_comp_array;
	std::unique_ptr<int[]> _three_p_comp_array;

	std::unique_ptr<int[]> sizes;
	size_t _size;

public:
	GraphicsManager(size_t size);

	void build_graph(const MODE mode) throw(FileManager::FileNotFoundException);

	~GraphicsManager()
	{
		std::cout << "GraphicsManager memory deallocated" << std::endl;
	}
};