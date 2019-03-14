#pragma once
#include "GameObject.h"

class Bird final:
	public GameObject
{
public:
	Bird();
	Bird(int, int, string, float, float);
	~Bird();
	void update();
	void move();
	void animate();
	bool getAlive();
	bool getPush();
	
private:
	float riseHeight;
	float speed;
	float currentFrame;
	float frameSpeed;
	float shiftY;
	bool alive;
	bool isPush;
};

