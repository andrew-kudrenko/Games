#include "Tubes.h"


Tubes::Tubes() 
{
}

Tubes::Tubes(int width, int height, string pathUp, string pathDown)
{	
	srand(time(NULL));
	imageUp.loadFromFile("graphics/" + pathUp);
	imageDown.loadFromFile("graphics/" + pathDown);
	textureUp.loadFromImage(imageUp);
	textureDown.loadFromImage(imageDown);
	tubeUp.setTexture(textureUp);
	tubeDown.setTexture(textureDown);
	numOfTubes = 5;
	size.x = width;
	size.y = height;
	whore = 150;

	for (int i = 0; i < numOfTubes; i++) 
	{
		coordsX.push_back(0);
		coordsY.push_back(0);
	}
	coordsX[0] = 0;
	coordsY[0] = rand() % size.y / 2 + GameInfo::window->getSize().y / 5;
	
	for (int i = 1; i < coordsX.size(); i++) 
	{
		coordsX[i] = coordsX[i - 1] + GameInfo::window->getSize().x / 3;
		coordsY[i] = rand() % size.y / 2 + GameInfo::window->getSize().y / 5;
	}
}


Tubes::~Tubes()
{
}

void Tubes::draw() 
{
	for (int i = 0; i < coordsX.size(); i++) 
	{
		tubeDown.setTextureRect(IntRect(0, size.y - coordsY[i], size.x, coordsY[i]));
		tubeDown.setPosition(coordsX[i], 0);
		GameInfo::window->draw(tubeDown);
		tubeUp.setTextureRect(IntRect(0, 0, size.x, GameInfo::groundY - coordsY[i] - whore));
		tubeUp.setPosition(coordsX[i], coordsY[i] + whore);
		GameInfo::window->draw(tubeUp);
	}
}

void Tubes::spawn(float x)
{
	if (coordsX[0] < x - GameInfo::window->getSize().x) {
		for (int i = 1; i < coordsX.size(); i++)
		{
			coordsX[i - 1] = coordsX[i];
			coordsY[i - 1] = coordsY[i];
		}
		coordsX[coordsX.size() - 1] = coordsX[coordsX.size() - 2] + GameInfo::window->getSize().x / 3;
		coordsY[coordsX.size() - 1] = rand() % size.y / 2 + GameInfo::window->getSize().y / 5;
		GameInfo::scores++;
	}
}

void Tubes::update(float x) 
{
	spawn(x);
	draw();
}

bool Tubes::isIntersected(float x, float y, float sizeY)
{
	for (int i = 0; i < coordsX.size(); i++) 
	{
		if ((x >= coordsX[i] && x <= coordsX[i] + size.x) && (y <= coordsY[i] || y + sizeY >= coordsY[i] + whore))
		{
			return true;
		}
	}
	return false;
}
