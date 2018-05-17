#ifndef CUSTOMERITEM_H
#define CUSTOMERITEM_H

// CustomerOrder Milestone - CustomerItem Interface
// CustomerItem.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>

class Item;

class CustomerItem {
	std::string name;  // name of the requested component 
	bool filled;       // status of the request
	unsigned int code; // unique shipping label
public:
	/*!Constructor that builds a CustomerItem object using a string object parameter*/
	CustomerItem(const std::string& = std::string());
	/*!Query member function that returns true if the current object's name is equal to the Item object reference parameter */
	bool asksFor(const Item&) const;
	/*!Query member function that returns the status of the object's request */
	bool isFilled() const;
	/*!Member function that sets filled to true and sets the item code to the parametered unsigned integer */
	void fill(const unsigned int);
	/*!Member function that sets the object in an empty state */
	void clear();
	/*!Query member function that returns the string object referencing this object's name */
	const std::string& getName() const;
	/*!Query member function that displays the object's details to the referenced ostream object parameter */
	void display(std::ostream&) const;
};

#endif //CUSTOMERITEM_H