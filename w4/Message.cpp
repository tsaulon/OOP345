#include "Message.h"
#include <iostream>

namespace w5
{
	Message::Message()
	{
		this->msg.clear();
		this->fromUser.clear();
		this->replyTo.clear();
	}

	Message::Message(std::ifstream& in, char c)
	{
		std::getline(in, this->fromUser, ' ');

		if (in.peek() == '@')
		{
			in.get();
			std::getline(in, this->replyTo, ' ');
		}

		std::getline(in, this->msg, c);

		//check if we extracted a newline character
		if (checkChar(this->fromUser, '\n'))
		{
			//remove previous fromUser extracted
			this->fromUser.assign(this->fromUser.substr((this->fromUser.find('\n') + 1), this->fromUser.length()));
		}
	}

	Message::~Message()
	{
	}

	void Message::display(std::ostream&) const
	{
		if (!this->msg.empty())
		{
			std::cout << "Message" << std::endl;
			std::cout << "\tUser\t:\t" << this->fromUser << std::endl;
			if (!this->replyTo.empty())
			{
				std::cout << "\tReply\t:\t" << this->replyTo << std::endl;
			}
			std::cout << "\tTweet\t:\t" << this->msg << std::endl;
		}

	}

	bool Message::checkChar(const std::string& aString, char check) const
	{
		bool replyExists = false;

		for (size_t i = 0; i < aString.length(); i++)
		{
			if (aString[i] == check)
			{
				replyExists = true;
			}
		}

		return replyExists;
	}
}
