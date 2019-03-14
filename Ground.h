#pragma once
#include "GameObject.h"
class Ground :
	public GameObject
{
public:
	Ground();
	Ground(int, int, string, float, float);
	~Ground();
	void draw(float);
};

