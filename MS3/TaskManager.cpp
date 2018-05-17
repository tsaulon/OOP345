#include <algorithm>
#include "TaskManager.h"
#include "Task.h"
#include "Item.h"
#include "ItemManager.h"

void TaskManager::validate(std::ostream& os)
{
	bool flag_1 = true;

	//std::vector<Task>::iterator i = this->begin()
	//auto feels shorter so...
	for (auto i = this->begin(); i != this->end() && flag_1; i++)
	{
		bool flag_2 = true;
		for (size_t ii = 0; ii < this->size() && flag_2; ii++)
		{
			if (i->validate(this->at(ii))) { flag_2 = false; };

			flag_1 = !flag_2;
		}
	}

	if (!flag_1)
	{
		os << "Not all Tasks have been validated" << std::endl;
	}
}

void TaskManager::validate(const ItemManager& obj, std::ostream& os)
{

	//1: Check tasks assigned exist in the base class container
	for(auto i = obj.begin(); i != obj.end(); i++)
	{
		if (std::find_if(this->begin(), this->end(), [&](const Task& x) { return x.getName() != i->getRemover(); }) == this->end())
		{
			os << i->getRemover() << " is not available " << std::endl;
		}
	}
}

void TaskManager::display(std::ostream& os) const
{
	for (auto i = this->begin(); i != this->end(); i++)
	{
		i->display(os);
	}
}