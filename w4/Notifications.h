#ifndef W5_NOTIFICATIONS_H
#define W5_NOTIFICATIONS_H
#include "Message.h"
#include <iostream>

namespace w5
{
	/*!Namespace w5 scoped variable that determines a maximum amount of messages.*/
	const size_t max_num_msg = 10;

	class Notifications
	{
		/*!Message object pointer to point to an array of messages.*/
		Message* messages;
		/*!A size_t variable to determine the amount of active indexes inside the messages array.*/
		size_t amntMsg;	//number of active messages in array

	public:
		/*!Notifications Default Constructor that also sets an empty state.*/
		Notifications();
		/*!Notifications member function modifier to initialize the current object to the same state as the parametered Notifications object.*/
		//Used by copy constructor and copy assignment operator.
		void init(const Notifications&);
		/*!Notifications copy constructor */
		Notifications(const Notifications&);
		/*!Notificaitons copy assignment operator*/
		Notifications& operator=(const Notifications&);
		/*!Notifications move constructor that creates a Notifications object using a parametered Rvalue Notifications object*/
		Notifications(Notifications&&);
		/*!Notifications move assignment operator that sets a Notifications object using a parametered Rvalue Notificationsn object*/
		Notifications& operator=(Notifications&&);
		/*!Notifications destructor which handles the lifecycle of the Message objects that are stored inside the Notification object.*/
		~Notifications();

		/*!Overloaded Notifications operator that adds a new Message object to the Notifications object Message array.*/
		void operator+=(const Message& msg);
		/*!Notifications query function that outputs the Messages held inside the Notifications object's Message array.*/
		void display(std::ostream& os) const;
	};
}


#endif //W5_NOTIFICATIONS_H