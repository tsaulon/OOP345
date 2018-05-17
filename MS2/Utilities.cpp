#include <iostream>
#include <cctype>
#include "Utilities.h"

char Utilities::delimiter = '|';
std::ofstream Utilities::logFile;

Utilities::Utilities() : field_width{ 1 } {}

const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more)
{
	/******************************************
	*			CLEAN FILE SOLUTION			  *
	*******************************************/

	std::string token = "";

	//continue if more to be extracted
	if (more)
	{
		//store string starting from next_pos 
		token = str.substr(next_pos);
		//store delimiter index
		size_t dl_pos = token.find(delimiter);
		//if delimiter was found
		if (dl_pos != std::string::npos) {
			//isolate token
			//erase rest of contents starting from end_pos
			token.erase(dl_pos, token.length());
		}

		//set next position to read from delimiter
		next_pos += token.length() + 1;
		if (next_pos > str.length()) {
			//flag no more extracting
			more = false;
		}


		/******************************************
		*	CLEAN FILE WITH WHITESPACE SOLUTION	  *
		*******************************************/

		std::string reverse = "";

		//remove trailing and leading white space.
		for (int j = 0; j < 2; j++) {

			//reverse string
			for (int i = token.length() - 1; i >= 0; i--) {
				reverse += token[i];
			}

			//remove leading whitespace
			if (std::isspace(reverse[0])) {
				reverse.erase(0, reverse.find_first_not_of(' '));
			}

			//reset
			token.assign(reverse);
			reverse.clear();
		}
	}

	//set field width
	if (this->field_width < token.length()) {
		this->field_width = token.length();
	}

	return token;
}