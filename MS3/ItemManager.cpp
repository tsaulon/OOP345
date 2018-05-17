#include "ItemManager.h"

void ItemManager::display(std::ostream& os, bool full) const
{
	for (std::vector<Item>::const_iterator i = this->begin(); i != this->end(); i++)
	{
		i->display(os, full);
	}
}