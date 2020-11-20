#include "Snake.h"

static unsigned snakeSize = WIDTH / 20;

Snake::Snake()
{
	bodyPart = new RectangleShape();
	bodyPart->setFillColor(Color::Red);
	bodyPart->setSize(Vector2f(100, 100));
	bodyParts.push_back(bodyPart);
}

Snake::Snake(unsigned x, unsigned y)
{
	bodyPart = new RectangleShape();
	bodyPart->setFillColor(Color::Red);
	unsigned snakeSize = x / 20;
	bodyPart->setSize(Vector2f(snakeSize, snakeSize));
	bodyParts.push_back(bodyPart);
	this->posX = 0;
	this->posY = 0;
	setSnakePos(posX, posY);
}

Snake::Snake(unsigned x, unsigned y, float posX, float posY)
{
	bodyPart = new RectangleShape();
	bodyPart->setFillColor(Color::Red);
	unsigned snakeSize = x / 20;
	bodyPart->setSize(Vector2f(snakeSize, snakeSize));
	this->posX = posX;
	this->posY = posY;
	setSnakePos(posX, posY);
}

Snake::~Snake()
{
	for (RectangleShape* shape : bodyParts) {
		delete shape;
	}
}

void Snake::setSnakePos()
{
	//Seting tail on the right place...
	vector<Vector2f> positions;
	for (unsigned i = 0; i < bodyParts.size(); i++) {
		positions.push_back(bodyParts[i]->getPosition());
	}
	for (unsigned i = 1; i < bodyParts.size(); i++) {
		bodyParts[i]->setPosition(positions[i - 1]);
	}

	if (moveLeft && !moveRight && !moveUp && !moveDown) {
		if (bodyPart->getPosition().x == 0) {
			setSnakePos(maxX * bodyPart->getGlobalBounds().width, bodyPart->getPosition().y);
		}
		else {
			setSnakePos(bodyPart->getPosition().x - bodyPart->getGlobalBounds().width, bodyPart->getPosition().y);
		}
	}
	if (moveRight && !moveLeft && !moveUp && !moveDown) {
		if (bodyPart->getPosition().x / bodyPart->getGlobalBounds().width == maxX) {
			setSnakePos(0, bodyPart->getPosition().y);
		}
		else {
			setSnakePos(bodyPart->getPosition().x + bodyPart->getGlobalBounds().width, bodyPart->getPosition().y);
		}
	}
	if (!moveRight && !moveLeft && !moveUp && moveDown) {
		if (bodyPart->getPosition().y == 0) {
			setSnakePos(bodyPart->getPosition().x, maxY * bodyPart->getGlobalBounds().height);
		}
		else {
			setSnakePos(bodyPart->getPosition().x, bodyPart->getPosition().y - bodyPart->getGlobalBounds().height);
		}
	}
	if (!moveRight && !moveLeft && moveUp && !moveDown) {
		if (bodyPart->getPosition().y / bodyPart->getGlobalBounds().height == maxY) {
			setSnakePos(bodyPart->getPosition().x, 0);
		}
		else {
			setSnakePos(bodyPart->getPosition().x, bodyPart->getPosition().y + bodyPart->getGlobalBounds().height);
		}
	}

	//Checkt for snake head-tail collision
	for (unsigned i = 1; i < bodyParts.size(); i++) {
		if (bodyParts[0]->getPosition() == bodyParts[i]->getPosition()) {
			eatTail = true;
		}
	}
}

void Snake::createNewBodyPart()
{
	RectangleShape* tempRecshape = new RectangleShape();
	tempRecshape->setFillColor(HelpTools::createNewColor());
	tempRecshape->setSize(Vector2f(WIDTH / 20, WIDTH / 20));
	bodyParts.push_back(tempRecshape);
	setNewBodyPartPosition();
}

void Snake::setNewBodyPartPosition()
{
	if (moveLeft) {
		cout << "Left\n";
		bodyParts[bodyParts.size() - 1]->setPosition(bodyParts[bodyParts.size() - 2]->getPosition().x + snakeSize, bodyParts[bodyParts.size() - 2]->getPosition().y);
		cout << bodyParts[bodyParts.size() - 2]->getPosition().x << " " << bodyParts[bodyParts.size() - 2]->getPosition().y << endl;
		cout << bodyParts[bodyParts.size() - 1]->getPosition().x << " " << bodyParts[bodyParts.size() - 1]->getPosition().y << endl;
	}	
	if (moveRight) {
		cout << "Right\n";
		bodyParts[bodyParts.size() - 1]->setPosition(bodyParts[bodyParts.size() - 2]->getPosition().x - snakeSize, bodyParts[bodyParts.size() - 2]->getPosition().y);
		cout << bodyParts[bodyParts.size() - 2]->getPosition().x << " " << bodyParts[bodyParts.size() - 2]->getPosition().y << endl;
		cout << bodyParts[bodyParts.size() - 1]->getPosition().y << " " << bodyParts[bodyParts.size() - 1]->getPosition().y << endl;
	}
	if (moveUp) {
		cout << "Up\n";
		bodyParts[bodyParts.size() - 1]->setPosition(bodyParts[bodyParts.size() - 2]->getPosition().x, bodyParts[bodyParts.size() - 2]->getPosition().y + snakeSize);
		cout << bodyParts[bodyParts.size() - 2]->getPosition().x << " " << bodyParts[bodyParts.size() - 2]->getPosition().y << endl;
		cout << bodyParts[bodyParts.size() - 1]->getPosition().y << " " << bodyParts[bodyParts.size() - 1]->getPosition().y << endl;
	}
	if (moveDown) {
		cout << "Down\n";
		bodyParts[bodyParts.size() - 1]->setPosition(bodyParts[bodyParts.size() - 2]->getPosition().x, bodyParts[bodyParts.size() - 2]->getPosition().y - snakeSize);
		cout << bodyParts[bodyParts.size() - 2]->getPosition().x << " " << bodyParts[bodyParts.size() - 2]->getPosition().y << endl;
		cout << bodyParts[bodyParts.size() - 1]->getPosition().y << " " << bodyParts[bodyParts.size() - 1]->getPosition().y << endl;
	}
}

void Snake::drawSnakeParts(RenderWindow& rwind)
{
	for (auto a : bodyParts) {
		rwind.draw(*a);
	}
}

