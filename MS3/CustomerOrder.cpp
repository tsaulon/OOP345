#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Utilities.h"
#include "Item.h"
#include <vector>
#include <string>
#include <iomanip>

size_t CustomerOrder::field_width = 0;

CustomerOrder::CustomerOrder(const std::string& str) : nOrders{ 0 }, order{ nullptr }
{
	Utilities x;
	size_t next_pos = 0;
	bool more = true;

	this->name = x.nextToken(str, next_pos, more);
	this->product = x.nextToken(str, next_pos, more);

	//extract orders
	std::vector<std::string> orders;
	while (more)
	{
		std::string tmp = x.nextToken(str, next_pos, more);

		if (!tmp.empty())
		{
			orders.push_back(tmp);
		}
	}

	//Dynamically allocate and populate order from orders vector object.
	this->nOrders = orders.size();
	this->order = new CustomerItem[nOrders];

	for (size_t i = 0; i < orders.size(); i++)
	{
		this->order[i] = CustomerItem(orders[i]);
	}

	//set field_width
	if (x.getFieldWidth() > this->field_width)
	{
		this->field_width = x.getFieldWidth();
	}
}

CustomerOrder::CustomerOrder(const CustomerOrder&)
{
	throw std::string("Copy constructor called - duplicates are not allowed.");
}

CustomerOrder::CustomerOrder(CustomerOrder&& object) NOEXCEPT : nOrders{ 0 }, order { nullptr }
{
	*this = std::move(object);
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& object) NOEXCEPT
{
	//check if same address
	if (this != &object)
	{
		//check if order object array is populated
		if (order)
		{
			delete[] order;
			order = nullptr;
		}
		
		//copy and assign
		this->name = object.name;
		this->product = object.product;
		this->nOrders = object.noOrders();
		this->order = object.order;

		//set object to empty state
		object.order = nullptr;
		object.nOrders = 0;
	}

	return std::move(*this);
}

CustomerOrder::~CustomerOrder()
{
	delete[] order;
}

unsigned int CustomerOrder::noOrders() const
{
	return this->nOrders;
}

const std::string& CustomerOrder::operator[](unsigned int index) const
{
	if (index > noOrders())
	{
		throw "Index is out of bounds.";
	}

	return this->order[index].getName();
}

void CustomerOrder::fill(Item& x)
{
	for (size_t i = 0; i < this->nOrders; i++)
	{
		if (this->order[i].getName() == x.getName() && !order[i].isFilled())
		{
			this->order[i].fill(x.getCode());
			x++;
		}
	}
}

void CustomerOrder::remove(Item& x)
{
	for (size_t i = 0; i < this->nOrders; i++)
	{
		if (this->order[i].getName() == x.getName())
		{
			this->order[i].clear();
		}
	}
}

bool CustomerOrder::empty() const
{
	return this->name.empty();
}

void CustomerOrder::display(std::ostream& os) const
{
	os << std::left << std::setw(field_width) << this->name + " : " << std::setw(field_width) << this->product << std::endl;
	for (size_t i = 0; i < noOrders(); i++)
	{
		order[i].display(os);
	}
}