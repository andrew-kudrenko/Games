#include "Ground.h"



Ground::Ground()
{
}

Ground::Ground(int width, int height, string path, float x, float y) : GameObject(width, height, path, x, y)
{
	coords.x = 0;
	coords.y = GameInfo::window->getSize().y - height;
}


Ground::~Ground()
{
}

void Ground::draw(float x) 
{
	if (x >= coords.x - size.x)
	{
		coords.x += size.x;
	}
	for (int i = 4; i >= 0; i--)
	{
		sprite.setPosition(coords.x - size.x * i, coords.y);
		GameInfo::window->draw(sprite);
	}
}