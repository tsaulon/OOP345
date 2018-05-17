#ifndef W5_MESSAGE_H
#define W5_MESSAGE_H
#include <iostream>
#include <fstream>
#include <string>

namespace w5
{
	class Message
	{
		/*!String object that holds the message.*/
		std::string msg;
		/*!String object that holds the name of the user the message came from.*/
		std::string fromUser;
		/*!String object that holds the name of the user that message is being sent to*/
		std::string replyTo;

	public:
		/*!Default constructor that sets an empty state Message object.*/
		Message();
		//!Constructor that builds a message object using a parametered reference to a file stream object and character.
		//!Character parameter deduces at what character file readingn should stop.*
		Message(std::ifstream& in, char c);
		/*!Message object Destructor.*/
		~Message();
	
		/*!Query member function that returns true if the Message object contains a message*/
		bool empty() const { return msg.empty(); };
		/*!Query member function that displays Member object details and send it to a paramatered referenced ostream object*/
		void display(std::ostream&) const;
		/*!Query member function that checks whether a specific character exists inside a string object.*/
		bool checkChar(const std::string& aString, char check) const;
	};
}


#endif //W5_MESSAGE_H