#include "Grades.h"

Grades::Grades() : stdID{ nullptr }, grade{ nullptr }, numRec { 0 } {}

Grades::Grades(const char* file) : stdID{ nullptr }, grade{ nullptr }, numRec{ 0 }
{
	try {
		readRecords(file);
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}

	if (numRec > 0)
	{
		stdID = new std::string[numRec];
		grade = new float[numRec];
		readRecords(file, true);
	}
}

Grades::~Grades()
{
	delete[] grade;
	delete[] stdID;
}

void Grades::readRecords(const char* aFile, bool save) {

	std::ifstream file;
	std::string tmp;

	file.open(aFile);

	if (file.is_open())
	{
		if (!save) {
			while (std::getline(file, tmp, '\n')) {
				numRec++;
			}
		}
		else {
			for (int i = 0; i < numRec; i++) {
				std::getline(file, tmp, ' ');
				stdID[i] = tmp;
				file >> grade[i];
				file.get();
			}

			file.ignore(2000, '\n');
		}
	}
	else
	{
		throw "File could not be opened!";
	}
}