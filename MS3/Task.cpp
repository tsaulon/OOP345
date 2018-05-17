#include <iostream>
#include <iomanip>
#include "Task.h"

size_t Task::field_width = 1;

Task::Task(const std::string& str)
{
	//initialize empty states
	this->slots = "1";
	this->pNextTask[passed] = nullptr;
	this->pNextTask[redirect] = nullptr;

	//Declare variables for str parsing
	bool more = true;
	size_t next_pos = 0;
	Utilities x;

	//parse strings
	this->name = x.nextToken(str, next_pos, more);
	this->slots = x.nextToken(str, next_pos, more);
	this->nextTask[passed] = x.nextToken(str, next_pos, more);
	this->nextTask[redirect] = x.nextToken(str, next_pos, more);

	//set field width if greater than current.
	if (x.getFieldWidth() > this->getFieldWidth()) {
		this->field_width = x.getFieldWidth();
	}

	if (slots.empty()) {
		this->slots = "1";
	}
}


bool Task::validate(const Task& task)
{
	if (nextTask[passed] == task.name) {
		this->pNextTask[passed] = &task;
	}
	
	if (nextTask[redirect] == task.name) {
		this->pNextTask[redirect] = &task;
	}

	return (nextTask[passed].empty() || pNextTask[passed]) && (nextTask[redirect].empty() || pNextTask[redirect]);
}

const Task* Task::getNextTask(Quality quality) const
{
	if (!this->pNextTask[quality]) {
		throw "*** Validate [" + this->nextTask[quality] + "] @ [" + this->name + "] ***";
	}

	return this->pNextTask[quality];
}

void Task::display(std::ostream& os) const
{
	os << "Task Name    : " << std::left << std::setw(this->getFieldWidth() + 5) << "[" + name + "]";
	os << "[" + this->slots + "]" << std::endl;

	if (!this->nextTask[passed].empty()) {
		os << " Continue to : " << std::left << std::setw(this->getFieldWidth() + 5) << "[" + this->nextTask[passed] + "]";
		if (this->pNextTask[passed] == nullptr) {
			os << " *** to be validated ***";
		}
		os << std::endl;
	}

	if (!this->nextTask[redirect].empty()) {
		os << " Redirect to : " << std::left << std::setw(this->getFieldWidth() + 5) << "[" + this->nextTask[redirect] + "]";
		if (this->pNextTask[redirect] == nullptr) {
			os << " *** to be validated ***";
		}
		os << std::endl;
	}

}

//helper function
bool operator==(const Task& a, const Task& b)
{
	//check if tasks have same name
	return a.getName() == b.getName();
}