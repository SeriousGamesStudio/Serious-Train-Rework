#include "Game.h"
#include "GraphicManager.h"
#include "PhysicsManager.h"
#include "InputManager.h"

void Game::init()
{
	try {
		GraphicManager::get().init();
		PhysicsManager::get().init();
		InputManager::get().init();
	}
	catch (std::exception e) {}
}

void Game::start()
{
}

void Game::stop()
{
}

Game::Game()
{
}


Game::~Game()
{
}