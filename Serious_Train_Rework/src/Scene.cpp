#include "Scene.h"
#include "Entity.h"
#include <algorithm>
Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::load(const char * sceneFile)
{
}

Entity * Scene::getEntity(const char * name)
{
	auto it = std::find_if(entities.begin(), entities.end(), [name](Entity*& e)->bool { return name == e->getName(); });
	if (it != entities.end())
		return (*it);
	return nullptr;
}

Entity * Scene::getEntity(ID id)
{
	auto it = std::find_if(entities.begin(), entities.end(), [id](Entity*& e)->bool { return e->getID() == id; });
	if (it != entities.end())
		return (*it);
	return nullptr;
}

void Scene::addEntity(Entity * entity)
{
	if (entity) 
	{
		if (!entity->hasBeenInitialized())
			throw std::exception("Tried to add a non initialized entity to the scene!");
		else
			entities.push_back(entity);
	}
}

void Scene::destroyEntity(Entity * entity)
{
	entities.erase(std::find(entities.begin(), entities.end(), entity));
	entity->destroy();
	delete entity;
}

void Scene::destroyEntity(const char * entityName)
{
	auto e = std::find_if(entities.begin(), entities.end(), [entityName](Entity*& e) {return entityName == e->getName(); });
	entities.erase(e);
	(*e)->destroy();
	delete *e;
}

void Scene::destroyEntity(const ID entityId)
{
	auto e = std::find_if(entities.begin(), entities.end(), [entityId](Entity*& e) {return entityId == e->getID(); });
	entities.erase(e);
	(*e)->destroy();
	delete *e;
}

