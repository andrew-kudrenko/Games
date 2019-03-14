#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(int width, int height, string path, float x = 0.f, float y = 0.f)
{
	coords.x = x;
	coords.y = y;
	size.x = width;
	size.y = height;
	image.loadFromFile("graphics/" + path);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, width, height));
}

GameObject::~GameObject()
{
}

void GameObject::draw() 
{
	sprite.setPosition(coords.x, coords.y);
	GameInfo::window->draw(sprite);
}

Vector2f GameObject::getCoords() 
{
	return coords;
}

Vector2u GameObject::getSize() 
{
	return size;
}
