#include <iomanip>
#include <iostream>
#include "Product.h"

namespace w7 {
	Product::Product() : prodNum{ 0 }, cost{ 0 } {}

	Product::Product(unsigned _prod, float _cost) : prodNum{ _prod }, cost{ _cost } {}

	Product::~Product()
	{
	}

	double Product::getCharge() const 
	{
		return this->cost;
	}

	void Product::display(std::ostream& os) const
	{
		os << std::right << std::setw(10) << this->prodNum << std::setw(10) << std::fixed << std::setprecision(2) << Product::getCharge() << std::setprecision(0);
	}
}

