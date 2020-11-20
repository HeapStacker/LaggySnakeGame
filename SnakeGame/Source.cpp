#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include "Snake.h"
#include "Apple.h"
#include <Windows.h>
#include "Jupmscare.h"

#define WIDTH 800
#define HEIGHT 600

using namespace std;
using namespace sf;
using namespace chrono_literals;

static Snake snake = Snake(WIDTH, HEIGHT);

static unsigned commonSize = snake.returnSnakePart()->getSize().x;

static Apple apple = Apple(WIDTH, HEIGHT, commonSize);

static chrono::high_resolution_clock::duration timer = 500000000ns;
static bool running = true;
static bool playEatingSound = false;
static unsigned counter1 = 0;
static unsigned counter2 = 0;
static unsigned counter3 = 0;
static SoundBuffer eatingSoundBuffer;
static Sound eatingSound;
static SoundBuffer niceShoutBuffer;
static Sound niceShout;

static bool collisionChecker() {
	if (snake.returnSnakeX() == apple.returnAppleX() && snake.returnSnakeY() == apple.returnAppleY()) {
		eatingSound.play();
		apple.generatXY();
		snake.createNewBodyPart();
		if (timer.count() > 200000000) {
			counter1++;
			timer -= 10000000ns * counter1;
		}
		else if (timer.count() > 100000000) {
			counter2++;
			timer -= 1000000ns * counter2;
		} 
		else {
			timer -= 1000000ns;
		}
		cout << "Collision\n";
		return true;
	}
	return false;
}


inline void gameFunctions();
inline void drawSnakeParts(RenderWindow& rwind);
static void setGameStuff();

int main(int argc, char* argv[]) {
	HWND consoleWind = GetConsoleWindow();
	ShowWindow(consoleWind, SW_HIDE);
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "SnakeGame", Style::Titlebar | Style::Close);
	Jupmscare jsOb = Jupmscare();
	Event event = Event();
	setGameStuff();
	if (!window.isOpen()) {
		cerr << "Window is not open.\n";
		return 1;
	}
	else {
		while (window.isOpen()) {
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case Event::Closed:
					window.close();
					break;
				case Event::KeyPressed:
					if (event.key.code == Keyboard::Escape)
						window.close();
					if (event.key.code == Keyboard::A) {
						snake.moveLeft = true;
						snake.moveRight = false;
						snake.moveUp = false;
						snake.moveDown = false;
					}
					if (event.key.code == Keyboard::D) {
						snake.moveLeft = false;
						snake.moveRight = true;
						snake.moveUp = false;
						snake.moveDown = false;
					}
					if (event.key.code == Keyboard::W) {
						snake.moveLeft = false;
						snake.moveRight = false;
						snake.moveUp = false;
						snake.moveDown = true;
					}
					if (event.key.code == Keyboard::S) {
						snake.moveLeft = false;
						snake.moveRight = false;
						snake.moveUp = true;
						snake.moveDown = false;
					}
					break;
				default:
					break;
				}
			}
			gameFunctions();

			window.clear();

			if (!snake.returnGameState()) {
				this_thread::sleep_for(timer);
				window.draw(apple.returnAppleSprite());
				drawSnakeParts(window);
			}
			else {
				niceShout.play();
				this_thread::sleep_for(7ms);
				jsOb.changAlpha();
				window.draw(jsOb.jumpScare);
			}
			window.display();
		}
	}	
	running = false;
	return 0;
}

inline void gameFunctions() {
	snake.setSnakePos();
	collisionChecker();
}

inline void drawSnakeParts(RenderWindow& rwind)
{
	snake.drawSnakeParts(rwind);
}

void setGameStuff()
{
	snake.maxX = apple.unitX - 1;
	snake.maxY = apple.unitY - 1;
	apple.generatXY();
	eatingSoundBuffer = SoundBuffer();
	niceShoutBuffer = SoundBuffer();
	eatingSound = Sound();
	niceShout = Sound();
	eatingSoundBuffer.loadFromFile("SoundsAndMusic/EatingSound.wav");
	eatingSound.setBuffer(eatingSoundBuffer);
	niceShoutBuffer.loadFromFile("SoundsAndMusic/AAAGH1.wav");
	niceShout.setBuffer(niceShoutBuffer);
}
