// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}

	Grades grades(argv[1]);

	// define the lambda expression for letter
	auto letter = [](float num)
	{
		std::string gradeLetter;

		if (num < 50) {
			gradeLetter = 'F';
		}
		else if (num >= 50 && num < 54) {
			gradeLetter = 'D';
		}
		else if (num >= 55 && num < 60) {
			gradeLetter = "D+";
		}
		else if (num >= 60 && num < 65) {
			gradeLetter = 'C';
		}
		else if (num >= 65 && num < 70) {
			gradeLetter = "C+";
		}
		else if (num >= 70 && num < 75) {
			gradeLetter = 'B';
		}
		else if (num >= 75 && num < 80) {
			gradeLetter = "B+";
		}
		else if (num >= 80 && num < 89) {
			gradeLetter = 'A';
		}
		else if (num > 89) {
			gradeLetter = "A+";
		}

		return gradeLetter;
	};

	grades.displayGrades(std::cout, letter);

	std::cout << "Press any key to continue ... ";
	std::cin.get();
}