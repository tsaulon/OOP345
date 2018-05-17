#include "Process.h"
#include <iostream>

namespace sict
{
	void process(const char* aString)
	{
		CString newString(aString);	//construct kingdom object from string received
		std::cout << newString;	//print kingdom
	}
}

