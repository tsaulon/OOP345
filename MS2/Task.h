// Task Milestone - Task Interface
// Task.h
// Chris Szalwinski
// v1.0 - 24/10/2015
// v2.0 - 23/02/2016
#ifndef TASK_H
#define TASK_H
#include <string>
#include "Utilities.h"

class Task {
	std::string name;          // name of the task
	std::string slots;         // number of slots
	std::string nextTask[2];   // names of the next tasks
	const Task* pNextTask[2];  // addresses of the next tasks
	static size_t field_width; // current maximum field width 
public:
	enum Quality {
		passed,
		redirect
	};

	/*!Object constructor that uses a parametered constant reference to a string object to create a Task object.*/
	Task(const std::string&);
	/*!Member function that recieves a constant reference to a Task object and compares the parametered object to the current object's nextTask.*/
	bool validate(const Task&);
	/*!Member function that returns the name of the current Task.*/
	const std::string& getName() const { return name; }
	/*!Member function that returns the number of slots within the current Task*/
	unsigned int getSlots() const { return std::stoi(slots); }
	/*!Member function that returns a pointer to the nextTask at the index of a parametered enum of this object.*/
	const Task* getNextTask(Quality) const;
	/*!Member function that displays details of the current object.*/
	void display(std::ostream&) const;
	/*!Member function that returns the field_width of the current object.*/
	static size_t getFieldWidth() { return field_width; }
};

/*!Helper function that compares two tasks.*/
bool operator==(const Task&, const Task&);

#endif