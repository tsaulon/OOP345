#ifndef W6_GRADES_H
#define W6_GRADES_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Grades
{
	/*!Class pointer that stores a dynamic array of std::string(s) of student IDs.*/
	std::string* stdID;
	/*!Class pointer that stores a dynamic array of float datatypes of grade percentages.*/
	float* grade;
	/*!Class variable that stores the amount of records stored in the object.*/
	size_t numRec;

public:
	/*!Class default constructor that defines an empty state.*/
	Grades();
	/*Class constructor that recieves a parametered character array of file name and pulls information from that file.*/
	Grades(const char* file);
	/*Prevention of instantiating a grades object using a lvalued Grades object.*/
	Grades(const Grades&) = delete;
	/*Prevention of instantiating a grades object using a rvalued Grades object.*/
	Grades(const Grades&&) = delete;
	/*Prevention of assignment to a grades object using a lvalued Grades object.*/
	Grades& operator=(const Grades&) = delete;
	/*Prevention of assignment to a grades object using a rvalued Grades object.*/
	Grades& operator=(const Grades&&) = delete;
	/*!Class destructor that cleans up dynamically allocated memory for stdID and grade arrays*/
	~Grades();

	/*!Class member function that reads a file and saves the contents depending on the boolean argument passed as a parameter.*/
	void readRecords(const char* aFile, bool save = false);

	/*!Class member template function that recieves a function and an ostream object reference and prints out the file details with the corresponding grade letter.*/
	template<typename Func>
	void displayGrades(std::ostream& os, Func func) const {

		for (int i = 0; i < numRec; i++) {
			os << std::fixed;
			os << std::setprecision(2);
			os << stdID[i] << ' ' << grade[i] << ' ' << func(grade[i]) << std::endl;
		}
	}
};

#endif // W6_GRADES_H