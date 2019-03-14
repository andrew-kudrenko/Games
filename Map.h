#pragma once
#include "GameObject.h"
class Map :
	public GameObject
{
public:
	Map();
	Map(int, int, string, float, float);
	~Map();
	void draw(float);
};

