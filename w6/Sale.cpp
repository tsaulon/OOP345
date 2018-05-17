#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "TaxableProduct.h"
#include "Product.h"
#include "Sale.h"

namespace w7 {
	Sale::Sale(const char* file) : total{ 0 }
	{
		iProduct* x;
		std::ifstream f;

		f.open(file);

		if (f.is_open())
		{
			while ((x = readProduct(f)) != nullptr)
			{
				productList.push_back(x);
			}
				
		}

		f.close();
	}


	Sale::~Sale()
	{
	}

	void Sale::display(std::ostream& os)
	{
		os << std::setw(10) << "Product No      " << std::right << "Cost Taxable" << std::endl;

		for (auto& x : productList)
		{
			x->display(os);
			os << std::endl;
			total += x->getCharge();
		}

		os << std::setw(10) << "Total" << std::fixed << std::setprecision(2) << std::setw(10) << total << std::endl;
	}

	iProduct* readProduct(std::ifstream& fs)
	{
		iProduct* x = nullptr;
		unsigned pNum;
		float cost;
		char status = '\0';

		std::string tmp;

		std::getline(fs, tmp, '\n');

		if (!tmp.empty())
		{
			pNum = std::stoi(tmp.substr(0, tmp.find_first_of(' ')));

			//check if status exists
			unsigned next = tmp.find_last_of(' ');

			//if exists
			if (next == tmp.find_first_of(' '))
			{
				cost = std::stof(tmp.substr(tmp.find_first_of(' '), tmp.find_last_of('\n')));
			}
			else 
			{
				cost = std::stof(tmp.substr(tmp.find_first_of(' '), tmp.find_last_of(' ')));
				status = tmp[tmp.length() - 1];
			}

			//create object
			x = (status == '\0') ? new Product(pNum, cost) : new TaxableProduct(pNum, cost, status);
		}

		return x;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& obj)
	{
		obj.display(os);

		return os;
	}
}
