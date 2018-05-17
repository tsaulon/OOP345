#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

// CustomerOrder Milestone - CustomerOrder Interface
// CustomerOrder.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>
#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

class Item;
class CustomerItem;

class CustomerOrder {
		std::string name;          // name of the customer
		std::string product;       // name of the product
		CustomerItem* order;       // address of the customer requests 
		unsigned int nOrders;      // number of requests
		static size_t field_width; // current maximum field width
	public:
		/*!Constructor that initializes the object using a string ready to be parsed */
		CustomerOrder(const std::string&);
		/*!Constructor that throws an exception when called as to not create duplications of the same object */
		CustomerOrder(const CustomerOrder&);
		/*!Object assignment operator never to be called */
		CustomerOrder& operator=(const CustomerOrder&) = delete; 
		/*!Move constructor that uses an R value CustomerOrder object reference to build a CustomerOrder object. */
		CustomerOrder(CustomerOrder&&) NOEXCEPT;
		/*!Move assignment operator that uses an R value CustomerOrder object reference to assign a CustomerOrder object. */
		CustomerOrder&& operator=(CustomerOrder&&) NOEXCEPT;
		/*!Destructor that handles the removal of dynamic datatypes */
		~CustomerOrder();
		/*!Query member function that returns the nOrders the current object has. */
		unsigned int noOrders() const;
		/*!Overloaded array operator that returns a reference to the name of the indexed parameter passed into this operator and throws an exception if out of bounds.*/
		const std::string& operator[](unsigned int) const;
		/*!Member function that searches through the customer items and fills the orders based on the Item object parametered. */
		void fill(Item&);
		/*!Member function that searches through the customer items and clears the orders based on the Item object parametered. */
		void remove(Item&);
		/*!Query member function that returns true if the current object is empty */
		bool empty() const;
		/*!Query member function that displays the object's details to the ostream object reference parameter */
		void display(std::ostream&) const;
};

#endif //CUSTOMERORDER_H