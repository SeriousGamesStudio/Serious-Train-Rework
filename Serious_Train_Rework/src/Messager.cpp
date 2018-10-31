#include "Messeger.h"
#include <algorithm>
Messenger::Messenger():
	activeMessages(_messages[0]), bufferMessages(_messages[1])
{
}

Messenger::~Messenger()
{
	for(int i = 0; i < 2; i++)
		if(!_messages[i].empty())
			for (Message* m : _messages[i]) 
				delete m;
}

void Messenger::tick()
{
	std::swap(activeMessages, bufferMessages);

	for(Message* m: activeMessages)
		for (Observer* o : observers[m->_id])
			o->recieve(m);

	[&] {
		for (Message* m : activeMessages)
			delete m;
		activeMessages.clear();
	}();
}

void Messenger::addObserver(MessageID id, Observer * obs)
{
	if(obs)
		observers[id].push_back(obs);
}

void Messenger::delObserver(MessageID id, Observer * obs)
{
	auto it = std::find(observers[id].begin(), observers[id].end(), obs);
	if (it != observers[id].end())
		observers[id].erase(it);
}

void Messenger::send(Message * msg)
{
	bufferMessages.push_back(msg);
}