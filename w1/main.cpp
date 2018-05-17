#include "CString.h"
#include "Process.h"
#include <iostream>

int main(int argc, char *argv[])
{

	bool error = false;

	std::cout << "Command Line : w1 ";

	if (argc < 2)
	{
		std::cout << std::endl;
		std::cout << "Insufficient number of arguments (min 1)" << std::endl;
		error = true;	//set error
		std::cout << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << argv[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Maximum number of characters stored: " << sict::max_str_length << std::endl;

		for (int i = 1; i < argc; i++)
		{
			sict::process(argv[i]);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}


	return error;
}