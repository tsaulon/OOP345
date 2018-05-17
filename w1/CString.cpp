#include "CString.h"

namespace sict
{
	//set empty state...
	CString::CString()
	{
		strcpy(this->m_string, "");
	}

	//set new CString params
	CString::CString(const char* aString)
	{
		//if exists; not null...
		if (aString)
		{
			//if string length of aName is > 32
			if (strlen(aString) > max_str_length)
			{
				//truncate; store first max length of aName param to m_name...
				for (int i = 0; i < max_str_length; i++)
				{
					this->m_string[i] = aString[i];
				}
				this->m_string[max_str_length] = '\0';
			}
			else
			{
				strcpy(this->m_string, aString);
			}
		}
		else
		{
			//no resources to handle
			//for copy assignment operator to be implemented...
			*this = CString();
		}
	}

	CString::~CString()
	{

	}

	std::ostream& CString::display(std::ostream& os) const
	{
		return os << this->m_string;
	}

	std::ostream& operator<<(std::ostream& os, const CString& aCString)
	{
		os << insertion_count++ << ": ";
		return aCString.display(os);
	}
}