#include "Notifications.h"


namespace w5
{
	Notifications::Notifications() : messages{ nullptr }, amntMsg{ 0 } {}

	Notifications::Notifications(const Notifications& newObject)
	{
		this->init(newObject);
	}

	Notifications& Notifications::operator=(const Notifications& newObject)
	{
		if (this != &newObject)
		{
			delete[] this->messages;
			this->init(newObject);
		}

		return *this;
	}

	void Notifications::init(const Notifications& newObject)
	{
		this->amntMsg = newObject.amntMsg;
		if (newObject.messages != nullptr)
		{
			this->messages = new Message[max_num_msg];
			for (size_t i = 0; i < this->amntMsg; i++)
			{
				this->messages[i] = newObject.messages[i];
			}
		}
		else
		{
			this->messages = nullptr;
		}
	}

	Notifications::Notifications(Notifications&& newObject)
	{
		this->messages = nullptr;
		*this = std::move(newObject);
	}

	Notifications& Notifications::operator=(Notifications&& newObject)
	{

		if (this != &newObject)
		{
			delete[] this->messages;

			this->messages = newObject.messages;
			this->amntMsg = newObject.amntMsg;

			newObject.messages = nullptr;
			newObject.amntMsg = 0;
		}

		return *this;
	}

	Notifications::~Notifications()
	{
		delete[] this->messages;
	}

	void Notifications::operator+=(const Message& msg)
	{
		if (this->messages == nullptr)
		{
			this->messages = new Message[max_num_msg];
		}

		if (this->amntMsg < max_num_msg)
		{
			this->messages[amntMsg] = msg;
			this->amntMsg++;
		}

	}

	void Notifications::display(std::ostream& os) const
	{
		for (size_t i = 0; i < this->amntMsg; i++)
		{
			this->messages[i].display(os);
			os << std::endl;
		}
	}

}
