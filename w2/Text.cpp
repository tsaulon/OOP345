#include "Text.h"
#include <fstream>
#include <string>

namespace w3
{
	Text::Text()
	{
		this->texts = nullptr;
		this->amntOfRecords = 0;
		this->recordsByteSize = 0;
	}

	Text::Text(const std::string aFile)
	{

		//count number of records inside file
		this->amntOfRecords = getSize(aFile);
		this->recordsByteSize = this->amntOfRecords;

		if (this->amntOfRecords > 0)
		{
			this->texts = new std::string[this->amntOfRecords];	//allocated dynamic memory
			getSize(aFile, true);	//save the records
		}
		else
		{
			*this = Text();
		}
	}

	Text::Text(const Text& aText)
	{
		this->init(aText);
	}

	Text::Text(Text&& aText)
	{
		this->texts = nullptr;	//ask professor if this will cause memory leak.
		*this = std::move(aText);
	}

	Text& Text::operator=(const Text& aText)
	{
		if (this != &aText)
		{
			delete[] this->texts;
			this->init(aText);
		}

		return *this;
	}

	Text& Text::operator=(Text&& aText)
	{
		if (this != &aText)
		{
			delete[] this->texts;
			init(aText);
		}

		return *this;
	}

	Text::~Text()
	{
		delete[] this->texts;
	}

	void Text::init(const Text& aText)
	{
		this->amntOfRecords = aText.amntOfRecords;
		this->recordsByteSize = aText.recordsByteSize;
		if (aText.texts)
		{
			this->texts = new std::string[amntOfRecords];
			for (int i = 0; i < amntOfRecords; i++)
			{
				this->texts[i].assign(aText.texts[i]);
			}
		}
		else
		{
			this->texts = nullptr;
		}
	}

	void Text::init(Text&& aText)
	{
		if (this != &aText)
		{
			//copy data from src aText
			this->texts = aText.texts;
			this->amntOfRecords = aText.amntOfRecords;
			this->recordsByteSize = aText.recordsByteSize;

			//delete RValue data
			aText.texts = nullptr;
			aText.amntOfRecords = 0;
			aText.recordsByteSize = 0;
		}

	}

	int Text::getSize(const std::string aFile, bool save)
	{
		std::ifstream file;
		std::string tmp;
		int size = 0;

		file.open(aFile);

		if (file.is_open())
		{
			for (int i = 0; std::getline(file, tmp, '\n'); i++)
			{
				size++;

				if (save)
				{
					this->texts[i] = tmp;
				}
			}
		}
		
		file.close();

		return size;
	}

	size_t Text::size() const
	{
		return this->recordsByteSize;
	}
}

