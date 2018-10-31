#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H
using Byte = char;
#include "Definitions.h"
//Here Add the message id
enum MessageID 
{
	size//this element MUST be always at the end
};

struct Message 
{
	Message(MessageID id, ID sender, ID reciever = NULL, Byte priority = 0) :
		_id(id), _sender(sender), _reciever(reciever), _priority(priority) 
	{}

	const MessageID _id;
	const Byte _priority;
	const ID _reciever;
	const ID _sender;
};
#endif // !MESSAGE_H
