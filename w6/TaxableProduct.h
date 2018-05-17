#pragma once
#include "Product.h"

namespace w7 {
	/*!TaxableProduct object that inherits from the Product object.*/
	class TaxableProduct : public Product
	{
		char taxStatus;
		float tax[2];

	public:
		/*!Enumerator to differentiate HST and PST for readability and my own experiment.*/
		enum Rate {
			H,
			P
		};

		/*!Constructor that initializes the object using a parametered unsigned integer, float datatype, and char datatype.*/
		TaxableProduct(unsigned _prod, float _cost, char _taxStatus);
		/*!Default constructor which initializes the object to an empty state.*/
		TaxableProduct();

		/*!Query member fucntion which returns the charge of the current object multiplied by the type of tax rating.*/
		double getCharge() const;
		/*!Query member function that outputs the object's details to the parametered ostream object reference.*/
		void display(std::ostream&) const;
	};

}

