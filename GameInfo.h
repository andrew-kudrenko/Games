#include <SFML/Graphics.hpp>
#pragma once
using namespace sf;

class GameInfo
{
public:
	GameInfo();
	~GameInfo();
	static float freeFallAcceleration;
	static float groundY;
	static RenderWindow *window;
	static unsigned int scores;
};

