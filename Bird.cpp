#include "Bird.h"


Bird::Bird()
{
}

Bird::Bird(int width, int height, string path, float x, float y) : GameObject(width, height, path, x, y)
{
	speed = 4.0f;
	riseHeight = -3.0f;
	alive = true;
	currentFrame = 0.f;
	frameSpeed = 0.4f;
	isPush = false;
	shiftY = 0.f;
}


Bird::~Bird()
{
}

bool Bird::getAlive() 
{
	return alive;
}

void Bird::move()
{
	if (Keyboard::isKeyPressed(Keyboard::W) && !isPush && coords.y > size.y)
	{
		coords.y += riseHeight;
		shiftY = riseHeight;
	}
	
	(Keyboard::isKeyPressed(Keyboard::W)) ? isPush : !isPush;

	coords.x += speed;
	coords.y += shiftY;

	shiftY += GameInfo::freeFallAcceleration;
	
	if (coords.y + size.y >= GameInfo::groundY) 
	{
		alive = false;
	}
}

void Bird::animate() 
{
	sprite.setTextureRect(IntRect((int)currentFrame * size.x, 0, size.x, size.y));
	currentFrame += frameSpeed;
	if (currentFrame >= 3) 
	{
		currentFrame = 0;
	}
}

void Bird::update() 
{
	animate();
	move();
	draw();
}

bool Bird::getPush() 
{
	return isPush;
}