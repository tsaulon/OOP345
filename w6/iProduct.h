#ifndef W7_IPRODUCT_H
#define W7_IPRODUCT_H
#include <iostream>
#include <fstream>

namespace w7 {
	/*!iProduct interface for the Product class to derive from.*/
	class iProduct {
	public:
		/*!Interface query function which returns the price of the product.*/
		virtual double getCharge() const = 0;
		/*!Interface query function which outputs the details of the current object to the ostream reference recieved.*/
		virtual void display(std::ostream&) const = 0;
	};

	/*!Overloaded helper operator that outputs the object, of the iProduct hierarchy, to the ostream reference parametered.*/
	std::ostream& operator<<(std::ostream&, const iProduct&);
	/*!Helper function that recieves a filestream and creates objects of the iProduct hierarchy and returns their addresses.*/
	iProduct* readProduct(std::ifstream&);
}

#endif //W7_IPRODUCT_H