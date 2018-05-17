#pragma once
#include "iProduct.h"

namespace w7 {
	/*!Product class which inherits from iProduct interface*/
	class Product :	public iProduct
	{
		unsigned prodNum;
		float cost;

	public:
		/*!Default constructor that initializes object to an empty state*/
		Product();
		/*!Constructor which recieves an unsigned integer and float datatype to initialize the object based on the given parameters.*/
		Product(unsigned _prod, float _cost);
		/*!Default constructor with no dynamic data to handle.*/
		~Product();

		/*!Query member function that returns the cost of the current object.*/
		double getCharge() const;
		/*!Query member function which displays the details of the current object to the ostream object reference recieved.*/
		void display(std::ostream&) const;
	};
}
