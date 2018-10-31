#pragma once
class GraphicManager
{
public:
	inline static GraphicManager& get() 
	{
		static GraphicManager gm;
		return gm;
	}

	void init();
	void free(); 

	void tick();

private:
	GraphicManager();
	~GraphicManager();
};

