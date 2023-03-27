#pragma once
#include<memory>
#include<string>

class FileManager {
private:
	std::unique_ptr<int[]> _array_1;
	std::unique_ptr<int[]> _array_2;
	std::unique_ptr<int[]> _array_3;
	std::string _filename;
	size_t _size;
public:

	class FileNotFoundException {
	public:
		const char* message() const {
			char buffer[255];
			strerror_s(buffer, errno);
			std::string message = "[ERROR] ";
			message += buffer;
			return message.c_str();
		}
	};

	FileManager(std::string filename);
	~FileManager()
	{
		std::cout << "Memory deallocated" << std::endl;
	}

	void write_data();
};