#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include <ctime>
#include <random>
using namespace std;
using namespace sf;
class Apple
{
	float commonSize = 0;
	unsigned appleX = 0, appleY = 0;
	Sprite appleSprite;
	Texture appleTexture;
public:
	unsigned unitX = 0, unitY = 0;
	Apple() {
	}
	Apple(unsigned WsizeX, unsigned WsizeY, float commonSize);
	Apple(unsigned x, unsigned y, unsigned WsizeX, unsigned WsizeY, float commonSize);
	~Apple() {
	}
	void generatXY();
	unsigned returnAppleX() {
		return appleX;
	}
	unsigned returnAppleY() {
		return appleY;
	}
	Sprite returnAppleSprite() {
		return appleSprite;
	}
};

