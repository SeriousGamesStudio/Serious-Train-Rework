#pragma once
#include "Definitions.h"
#include "Messeger.h"
class Entity;

template<typename T> inline const ID getComponentID() 
{
	return getTypeID<T>();
}

template<typename T> inline const ID getComponentID(T* c) 
{
	return getTypeID<T>();
}
#define  GET_COMPONENT_ID inline const ID getID() const { return getComponentID(this);}

class Component:
	public Observer, public Sender
{
public:
	Component(Messenger* messenger) :
		Observer(messenger), Sender(messenger)
	{};
	~Component() {};

	virtual void awake() {};
	virtual void start() {};
	virtual void update() {};
	virtual const ID getID() const = 0;


	inline void enable()		{ _enable = true; };
	inline void disable()		{ _enable = false; };
	inline void toggleEnable()	{ _enable = !_enable; };
	inline void setEnable(bool enable) { _enable = enable; };
	inline bool isEnable() const { return _enable; }
protected:
	friend class Entity;
	Entity * owner;
	bool _enable;
};