#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameInfo.h"
#include "GameObject.h"
#include "Bird.h"
#include "Map.h"
#include "Ground.h"
#include "Tubes.h"
#include "Game.h"
using namespace sf;
using namespace std;

int main() 
{
	/*
	GameInfo::scores = 0;
	int windowWidth = 1920, windowHeight = 1080;
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Flappy Bird");
	Image ico;
	ico.loadFromFile("graphics/icon.png");
	window.setIcon(32, 22, ico.getPixelsPtr());
	GameInfo::window = &window;
	View camera;
	camera.setSize(window.getSize().x, window.getSize().y);
	Bird bird(70, 48, "bird.png", -windowWidth / 2, GameInfo::groundY / 2);
	Map map(485, 864, "bg.png", 0, 0);
	Ground ground(648, 216, "ground.png", 0, 0);
	GameInfo::groundY = ground.getCoords().y;
	Tubes tube(80, 412, "tubeUp.png", "tubeDown.png");
	bool aGame = true;
	window.setVerticalSyncEnabled(true);
	*/
	/*
	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed) 
			{
				window.close();
			}
		}
		window.setView(camera);
		camera.setCenter(bird.getCoords().x, windowHeight / 2);
		window.clear();
		map.draw(bird.getCoords().x);
		ground.draw(bird.getCoords().x);
		tube.update(bird.getCoords().x);
		bird.update();
		window.display();

		if (bird.getCoords().x > GameInfo::scores * window.getSize().x / 2) 
		{
			GameInfo::scores++;
		}

		if (tube.isIntersected(bird.getCoords().x, bird.getCoords().y, bird.getSize().y) || !bird.getAlive()) 
		{
			aGame = false;
		}

		if (!aGame) 
		{
			break; 
		}
		cout << GameInfo::scores << "|\t\t|" << bird.getCoords().x << "|\t\t|" << bird.getPush() << endl;
	}
	*/
	Game play;
	play.game();
	return 0;
}