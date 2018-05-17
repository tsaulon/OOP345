#include "TaxableProduct.h"

namespace w7 {
	TaxableProduct::TaxableProduct() : taxStatus{ ' ' }
	{
		tax[H] = 1.13;
		tax[P] = 1.08;
	}

	TaxableProduct::TaxableProduct(unsigned _prod, float _cost, char _taxStatus) : taxStatus{ _taxStatus }, Product::Product(_prod, _cost)
	{
		tax[H] = 1.13;
		tax[P] = 1.08;
	}

	double TaxableProduct::getCharge() const
	{
		Rate rate;

		switch (this->taxStatus)
		{
		case 'H':
			rate = H;
			break;
		case 'P':
			rate = P;
			break;
		}

		return Product::getCharge() * tax[rate];
	}

	void TaxableProduct::display(std::ostream& os) const
	{
		Product::display(os);
		os << " ";

		if (this->taxStatus == 'H')
		{
			os << "HST";
		}
		else
		{
			os << "PST";
		}
	}
}

