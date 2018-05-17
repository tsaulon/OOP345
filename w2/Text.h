#ifndef W3_TEXT_H
#define W3_TEXT_H
#include <iostream>
#include <cstddef>

namespace w3
{
	class Text
	{
		/*!Array of strings to hold records of file objects.*/
		std::string* texts;
		/*!Amount of Records to determine size of array to iterate.*/
		int amntOfRecords;
		/*!Size of records determined by it's size in bytes; queried through size() function.*/
		size_t recordsByteSize;

	public:
		/*!Default Constructor to instantiating an empty state*/
		Text();
		/*!One string argument constructor to store contents of file parameter in Text object.*/
		Text(const std::string aFile);
		/*!Copy constructor, instantiating a new instance of Text object using copied data from aText parameter.*/
		Text(const Text& aText);
		/*!Move constructor, instantiating a new instance of Text object using an R value parameter.*/
		Text (Text&& aText);
		/*!Copy assignment operator, copying new data to a pre-existing Text object.*/
		Text& operator=(const Text& aText);
		/*!Move assignment operator, copying new data from an R value Text object to a pre-existing Text object.*/
		Text& operator=(Text&& aText);
		/*!Destructor, releasing dynamic memory from instance of std::string texts.*/
		~Text();

		/*!Resource handling for copy assignment operator and copy constructor*/
		void init(const Text& aText);
		/*!Resource handling for move assignment operator and move constructor*/
		void init(Text&& aText);
		/*!Function that gets size of the records inside a text file; option to save those contents*/
		int getSize(const std::string, bool save = false);
		/*!Function that gets size expressed in bytes.*/
		size_t size() const;
	};
}


#endif //W3_TEXT_H