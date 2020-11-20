#pragma once
#include <iostream>
#include <vector>
#include "Apple.h"
#include "SFML/Graphics.hpp"
#include "DefineFile.h"
#include "HelpTools.h"

using namespace std;
using namespace sf;

class Snake
{
	int a = 10;
	RectangleShape* bodyPart = nullptr;
	vector<RectangleShape*> bodyParts;
	float posX = 0, posY = 0;
	unsigned snakeX = 0, snakeY = 0;
	bool eatTail = false;
public:
	bool moveLeft = false;
	bool moveRight = false;
	bool moveUp = false;
	bool moveDown = false;
	unsigned maxX = 0, maxY = 0;
	Snake();
	Snake(unsigned x, unsigned y);
	Snake(unsigned x, unsigned y, float posX, float posY);
	~Snake();
	void setSnakePos();
	void setSnakePos(float x, float y) {
		bodyPart->setPosition(x, y);
	}
	unsigned returnSnakeX() {
		snakeX = bodyPart->getPosition().x / bodyPart->getGlobalBounds().width;
		return snakeX;
	}
	unsigned returnSnakeY() {
		snakeY = bodyPart->getPosition().y / bodyPart->getGlobalBounds().height;
		return snakeY;
	}
	void createNewBodyPart();
	void setNewBodyPartPosition();
	void drawSnakeParts(RenderWindow& rwind);
	bool returnGameState() const {
		return eatTail;
	}
	RectangleShape* returnSnakePart() const {
		return bodyPart;
	}
};

