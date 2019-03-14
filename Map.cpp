#include "Map.h"



Map::Map()
{
}

Map::Map(int width, int height, string path, float x = 0, float y = 0) : GameObject(width, height, path, x, y) 
{
}


Map::~Map()
{
}

void Map::draw(float x)
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