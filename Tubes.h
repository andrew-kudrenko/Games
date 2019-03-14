#include <SFML/Graphics.hpp>
#include <vector>
#include "GameInfo.h"
#include <ctime>
#pragma once
using namespace sf;
using namespace std;

class Tubes
{
public:
	Tubes();
	Tubes(int, int, string, string);
	~Tubes();
	void draw();
	void spawn(float);
	void update(float);
	bool isIntersected(float, float, float);

private:
	int numOfTubes;
	float whore;
	Image imageUp;
	Image imageDown;
	Texture textureUp;
	Texture textureDown;
	Sprite tubeUp, tubeDown;
	vector <float> coordsX;
	vector <float> coordsY;
	Vector2u size;
};

