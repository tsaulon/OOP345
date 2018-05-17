// Manager Milestone - TaskManager Interface
// TaskManager.h
// Chris Szalwinski
// v1.0 - 14/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <vector>

class Task;
class ItemManager;

/*!TaskManager object that manages it's vector object base class populated with Task objects.*/
class TaskManager : public std::vector<Task> {
public:
	/*!Member function that validates a task against all tasks inside the base class and appends a message if it is not validated. */
	void validate(std::ostream&);
	/*!Member function that tasks to handle the ItemManager object reference exist within the base class. Appends a message if the task does not exist.*/
	void validate(const ItemManager&, std::ostream&);
	/*!Member function that outputs descriptions of the tasks stored in the base class. */
	void display(std::ostream&) const;
};