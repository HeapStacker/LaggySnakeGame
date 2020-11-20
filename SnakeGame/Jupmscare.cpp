#include "Jupmscare.h"

Jupmscare::Jupmscare()
{
	if (!scaryTexture.loadFromFile("Assets/zmby.png")) {
		cerr << "Failed to load a texture.\n";
		exit(1);
	}
	jumpScare.setTexture(&scaryTexture);
	jumpScare.setSize(Vector2f(WIDTH, HEIGHT));
	jumpScare.setFillColor(Color(255, 255, 255, 10));
}
