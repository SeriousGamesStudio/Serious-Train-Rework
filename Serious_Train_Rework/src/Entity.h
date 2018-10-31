#pragma once
#include "Definitions.h"
#include <vector>
#include <atomic>
#include <initializer_list>
class Component;

class Entity
{
public:
	Entity(const char* name);
	~Entity();

	void destroy();

	void init(std::initializer_list<Component*> components);

	void awake();
	void start();
	void update();

	void addComponent(Component* newComponent);
	void delComponent(Component* newComponent);

	template<typename COMPONENT>
	COMPONENT* getComponent();

	inline const ID getID() const { return id; };
	inline const char* getName() const { return name; };
	inline const bool hasBeenInitialized() const { return initialized; };

private:
	std::atomic<bool> initialized;
	ID id;
	const char* name;
	std::vector<Component*> components;
};
