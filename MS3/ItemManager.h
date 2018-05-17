// Manager Milestone - ItemManager Interface
// ItemManager.h
// Chris Szalwinski
// v1.0 - 14/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <vector>
#include "Item.h"

/*!ItemManager object that derives from a vector class of Item type. */
class ItemManager : public std::vector<Item> {
public:
	/*!Member function that outputs item descriptions inside the base class. */
	void display(std::ostream&, bool = false) const;
};