#pragma once
#ifndef H_GAME_H
#define H_GAME_H
#include <stdint.h>
class Game
{
public:

	Game(const Game&) = delete;
	Game(const Game&&) = delete;

	static Game& get()
	{
		static Game g;
		return g;
	}

	void init();
	void start();
	void stop();

	inline uint32_t getTime() { return _time; };
	inline uint32_t getDeltaTime() { return _deltaTime; };

private:
	Game();
	~Game();

private:

	uint32_t _time;
	uint32_t _deltaTime;
};
#endif // !H_GAME_H