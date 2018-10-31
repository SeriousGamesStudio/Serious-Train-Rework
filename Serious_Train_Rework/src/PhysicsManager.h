#pragma once
#include "Physics.hpp"

class PhysicsManager
{
public:
	inline static PhysicsManager& get()
	{
		static PhysicsManager pm;
		return pm;
	}

	void init();
	void tick();
	void free();
private:

	PhysicsManager();
	~PhysicsManager();
};

