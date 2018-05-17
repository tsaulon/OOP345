#ifndef UTILITIES_H
#define UTILITIES_H

// Milestone 1 - Utilities Interface
// Utilities.h
// Chris Szalwinski
// v1.0 - 24/10/2015
// v2.0 - 23/02/2016
#include <string>
#include <fstream>

class Utilities {
	size_t field_width;           // maximum field width needed 
	static char delimiter;        // field delimiter character
	static std::ofstream logFile; // log file
public:
	/*!Default constructor sets object to empty state with field width of 1.*/
	Utilities();
	/*!Member function that returns the field_width of this object.*/
	size_t getFieldWidth() const { return field_width; }
	/*!Member function that retrives a reference to a string to parse, a reference to a size_t datatype to reference a position of where in the string to begin parsing,
	  a reference to a bool datatype to flag whether or not parsing can be continued.
	  This member function returns the parsed token referenced by a parametered string reference.*/
	const std::string nextToken(const std::string&, size_t&, bool&);
	/*!Static member function that sets the delimiter when string parsing.*/
	static void setDelimiter(const char c) { delimiter = c; }
	/*!Static member function that closes an open std::ofstream object and creates a new std::ofstream object from the character array paramatered to this function.*/
	static void setLogFile(const char* name) { 
		if (logFile.is_open()) { logFile.close(); }
		logFile.open(name); 
	}
	/*!Static member function that retrieves a reference to a std::ofstream object.*/
	static std::ofstream& getLogFile() { return logFile; }
};

#endif 