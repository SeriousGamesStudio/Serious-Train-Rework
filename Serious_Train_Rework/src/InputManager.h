#pragma once
class InputManager
{
public:
	inline static InputManager& get()
	{
		static InputManager im;
		return im;
	}

	void init();
	void tick();
	void free();
private:
	InputManager();
	~InputManager();
};

