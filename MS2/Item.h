#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

const unsigned int CODE_WIDTH = 5;

class Item {
		std::string name;          // name of the component
		std::string filler;        // name of the filler task
		std::string remover;       // name of the remover task 
		std::string description;   // detailed description
		unsigned int code;         // next shipping label
		static size_t field_width; // current maximum field width
	public:
		/*!Constructor that builds an Item object from a string object ready to be parsed.*/
		Item(const std::string& = std::string());
		/*!Query member function that returns true if the object is in an empty state. */
		bool empty() const;
		/*!Overloaded operator that increments the code and returns a reference to the current Item object.*/
		Item& operator++(int);
		/*!Query member function that returns the code value. */
		unsigned int getCode() const;
		/*!Query member function that returns the name of the current object. */
		const std::string& getName() const;
		/*!Query member function that returns the filler of the current object. */
		const std::string& getFiller() const;
		/*!Query member function that returns the remover of the current object. */
		const std::string& getRemover() const;
		/*!Member object that recieves a reference to an ostream object and displays an object based on the boolean value */
		void display(std::ostream&, bool = false) const;
};
#endif //ITEM_H