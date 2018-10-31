#pragma once
#include <vector>
#include "Definitions.h"
//Foward declarations
class Entity;

class Scene 
{
public:
	Scene();
	~Scene();

	void load(const char* sceneFile);

	Entity* getEntity(const char* name);
	Entity* getEntity(ID id);

	void addEntity(Entity* entity);

	void destroyEntity(Entity* entity);
	void destroyEntity(const char* entityName);
	void destroyEntity(const ID entityId);
	
private:
	std::vector<Entity*> entities;
};