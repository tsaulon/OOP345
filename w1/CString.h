/*! *********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date January, 25, 2018
// Author Tyrone Saulon
// Description:
// Week 1 Lab
***********************************************************/
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H
#include <iostream>
#include <cstring>

/*!A namespace dedicated to Seneca College.*/
namespace sict {
	
	/*!Maximum length of strings recorded.*/
	const int max_str_length = 3;	//maximum string length.
	/*!Counting time insertion operator is used.*/
	static int insertion_count = 0;	//tracking number of insertions.

	/*Class which encapsulates properties of a CString.*/
	class CString {
		/*Stores the string with the length of max_str_length.*/
		char m_string[max_str_length];

	public:
		/*!Empty state constructor.*/
		CString();
		/*!Param a pointer to a string.*/
		CString(const char* aString);
		/*!Destructor; */
		virtual ~CString();

		/*!Query function to display contents of CString*/ 
		std::ostream& display(std::ostream&) const;
	};

	/*!Helper function to display contents of CString when using it with insertion operator.*/
	std::ostream& operator <<(std::ostream& os, const CString& aCString);

}

#endif //SICT_KINGDOM_H