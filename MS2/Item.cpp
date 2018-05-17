#include "Item.h"
#include "Utilities.h"
#include <iomanip>
#include <iostream>

size_t Item::field_width = 0;

Item::Item(const std::string& str) : code{ 1 }
{

	Utilities x;
	size_t next_pos = 0;
	bool more = true;

	this->name = x.nextToken(str, next_pos, more);
	if (this->name.empty())
	{
		throw std::string("No name specified");
	}

	this->filler = x.nextToken(str, next_pos, more);
	if (this->filler.empty())
	{
		throw std::string("No task specified");
	}

	this->remover = x.nextToken(str, next_pos, more);
	if (this->remover.empty())
	{
		throw std::string("No remover specified");
	}

	this->code = std::stoi(x.nextToken(str, next_pos, more));

	this->description = x.nextToken(str, next_pos, more);
	if (this->description.empty())
	{
		this->description = "no detailed description";
	}
	
	if(getName().length() > field_width)
	{
		field_width = x.getFieldWidth();
	}
}

bool Item::empty() const
{
	return this->name.empty();
}

Item& Item::operator++(int)
{
	code++;

	return *this;
}

unsigned int Item::getCode() const
{
	return this->code;
}

const std::string& Item::getName() const
{
	return this->name;
}

const std::string& Item::getFiller() const
{
	return this->filler;
}

const std::string& Item::getRemover() const
{
	return this->remover;
}

void Item::display(std::ostream& os, bool full) const
{
	os << std::left << std::setfill(' ') << std::setw(field_width) << getName();
	os << '[' << std::right << std::setfill('0') << std::setw(CODE_WIDTH) << getCode() << ']';

	if (full)
	{
		os << std::left << std::setfill(' ') << std::setw(field_width) << " From " + getFiller();
		os << std::setw(field_width) << " To " + getRemover();
		os << std::endl;
		os << std::setw(field_width + CODE_WIDTH + 3) << std::right << " : " << this->description;
	}

	os << std::endl;
}