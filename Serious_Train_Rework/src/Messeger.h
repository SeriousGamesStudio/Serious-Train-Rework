#pragma once
#ifndef _MESSENGER_H
#define _MESSENGER_H

#include "Message.hpp"
#include <initializer_list>
#include <list>
#include <vector>
#include <atomic>
#include <array>

struct Observer;
struct Sender;

class Messenger 
{
	friend struct Observer;
	friend struct Sender;
public:
	Messenger();
	~Messenger();

	void tick();

private:
	void addObserver(MessageID id, Observer* obs);
	void delObserver(MessageID id, Observer* obs);

	void send(Message* msg);
private:
	std::list<Message*> _messages[2];
	std::list<Message*>& activeMessages;
	std::list<Message*>& bufferMessages;

	std::array<std::vector<Observer*>, MessageID::size> observers;
	std::atomic_bool isSendingMsg;
};
struct Observer 
{
	Observer(Messenger* m) : m(m) {}
	~Observer() 
	{
		unSuscribeAll();
	}
	void suscribeTo(MessageID id) 
	{
		suscriptions.push_back(id);
		m->addObserver(id, this);
	};
	void suscribeTo(std::initializer_list<MessageID> ids) 
	{
		for (auto&& id : ids)
			suscribeTo(id);
	};
	void unSuscribe(MessageID id) 
	{
		m->delObserver(id, this);
	};
	void unSuscribeAll() 
	{
		if (!suscriptions.empty()) for (auto i : suscriptions)
			unSuscribe(i);
	};
	virtual void recieve(Message* msg) = 0;
private:
	Messenger* m;
	std::vector<MessageID> suscriptions;
};
struct Sender
{
	Sender(Messenger* messenger) : m(messenger) {}
	void send(Message* msg) 
	{
		m->send(msg);
	};
private:
	Messenger * m;
};
#endif
