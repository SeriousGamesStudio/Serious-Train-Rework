#include "Entity.h"
#include "Component.h"
#include <algorithm>

Entity::Entity(const char* name):
	name(name), id(idGenerator())
{

}

Entity::~Entity()
{
}

void Entity::destroy()
{
	for (auto&& c : components) 
	{
		delete c;
		c = nullptr;
	}
	id = -1;
	name = "";
}

void Entity::init(std::initializer_list<Component*> components)
{
	for (auto&& component : components) 
	{
		component->owner = this;
		this->components.push_back(component);
	}
}

void Entity::awake()
{
	for (Component* c : components)
		if(c->isEnable())
			c->awake();
}

void Entity::start()
{
	for (auto &c : components)
		if (c->isEnable())
			c->start();
}

void Entity::update()
{
	for (auto &c : components)
		if (c->isEnable())
			c->update();
}

void Entity::addComponent(Component * newComponent)
{
	if (newComponent) 
	{
		newComponent->owner = this;
		components.push_back(newComponent);
	}
}

void Entity::delComponent(Component * newComponent)
{
	auto it = std::find(components.begin(), components.end(), newComponent);
	if (it != components.end()) delete *it;
	components.erase(it);
}

template<typename COMPONENT>
COMPONENT* Entity::getComponent() 
{
	for (Component* component : components)
		if (c->getID() == getComponentID<COMPONENT>())
			return static_cast<COMPONENT*>(component);
	return nullptr;
};