// Manager Milestone - OrderManager Interface
// OrderManager.h
// Chris Szalwinski
// v1.0 - 14/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <vector>

class ItemManager;
class CustomerOrder;

/*!OrderManager object which derives from a vector class of datatype CustomerOrder.*/
class OrderManager : public std::vector<CustomerOrder> {
public:
	/*!Member function that moves a CustomerOrder from the back of the base class container and returns that object as an r valued object.*/
	CustomerOrder&& extract();
	/*!Member function that checks that the items requested are available. Appends a message if it is not available.*/
	void validate(const ItemManager&, std::ostream&);
	/*!Member function that outputs the descriptions of each customer order inside the base class to the ostream object reference parametered.*/
	void display(std::ostream&) const;
};