#include <SFML/Graphics.hpp>
#include "GameInfo.h"
#pragma once
using namespace sf;
using namespace std;

class GameObject
{
public:
	GameObject();
	GameObject(int, int, string, float, float);
	~GameObject();
	Vector2f getCoords();
	Vector2u getSize();
	void draw();

protected:
	Vector2f coords;
	Vector2u size;
	Image image;
	Texture texture;
	Sprite sprite;
};

