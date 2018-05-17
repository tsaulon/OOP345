#include <algorithm>
#include "OrderManager.h"
#include "CustomerOrder.h"
#include "ItemManager.h"

CustomerOrder&& OrderManager::extract()
{
	return std::move(*this->end());
}

void OrderManager::validate(const ItemManager& obj, std::ostream& os)
{
	//iterate through base class vector
	for (std::vector<CustomerOrder>::iterator i = this->begin(); i != this->end(); i++)
	{
		//iterate through orders
		for (size_t ii = 0; ii < i->noOrders(); ii++)
		{
			//print message if item is unavailable.
			if (std::find_if(obj.begin(), obj.end(), [&](const Item& item) { return item.getName() != (*i)[ii]; }) == obj.end())
			{
				os << (*i)[ii] << " is unavailable. " << std::endl;
			}
		}
	}
}

void OrderManager::display(std::ostream& os) const
{
	for (std::vector<CustomerOrder>::const_iterator i = this->begin(); i < this->end(); i++)
	{
		i->display(os);
	}
}