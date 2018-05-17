#pragma once
#ifndef W7_SALE_H
#define W7_SALE_H
#include "iProduct.h"
#include <iostream>
#include <vector>
namespace w7 {
	/*!Class that holds information about a set of products sold to a customer.*/
	class Sale
	{
		float total;
		std::vector<iProduct*> productList;

	public:
		Sale(const char* file);
		~Sale();

		void display(std::ostream& os);
	};
}

#endif //W6_SALE_H