#include "Apple.h"

Apple::Apple(unsigned WsizeX, unsigned WsizeY, float commonSize)
{
	srand(time(nullptr));
	appleX = 0;
	appleY = 0;
	unitX = WsizeX / commonSize;
	unitY = WsizeY / commonSize;
	this->commonSize = commonSize;
	if (!appleTexture.loadFromFile("Assets/apple.png")) {
		cerr << "Couldn't load apple texture.\n";
		exit(1);
	}
	else {
		appleSprite.setTexture(appleTexture);
		appleSprite.setScale(0.1, 0.1);
	}
}

Apple::Apple(unsigned x, unsigned y, unsigned WsizeX, unsigned WsizeY, float commonSize)
{
	srand(time(nullptr));
	appleX = x;
	appleY = y;
	unitX = WsizeX / commonSize;
	unitY = WsizeY / commonSize;
	this->commonSize = commonSize;
	if (!appleTexture.loadFromFile("Assets/apple.png")) {
		cerr << "Couldn't load apple texture.\n";
		exit(1);
	}
	else {
		appleSprite.setTexture(appleTexture);
		appleSprite.setScale(0.1, 0.1);
	}
}

void Apple::generatXY()
{
	if (unitX && unitY) {
		appleX = rand() % unitX - 1;
		appleY = rand() % unitY - 1;
		if (appleX < 0 || appleX > unitX - 1)
			generatXY();
		if (appleY < 0 || appleY > unitX - 1)
			generatXY();
		appleSprite.setPosition(appleX * commonSize, appleY * commonSize);
	}
}
