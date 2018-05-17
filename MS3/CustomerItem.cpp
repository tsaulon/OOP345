#include "CustomerItem.h"
#include "Item.h"
#include <iomanip>

CustomerItem::CustomerItem(const std::string& str) : code{ 0 }, filled{ false }
{
	this->name.assign(str);
}

bool CustomerItem::asksFor(const Item& x) const
{
	return this->getName() == x.getName();
}

bool CustomerItem::isFilled() const
{
	return this->filled;
}

void CustomerItem::fill(const unsigned int itemCode)
{
	this->code = itemCode;
	this->filled = true;
}

void CustomerItem::clear()
{
	this->filled = false;
	this->code = 0;
}

const std::string& CustomerItem::getName() const
{
	return this->name;
}

void CustomerItem::display(std::ostream& os) const
{
	os << ((isFilled()) ? '+' : '-') << " [" << std::right << std::setw(CODE_WIDTH) << std::setfill('0') << code << "] " << std::setfill(' ') << this->getName() << std::endl;
}