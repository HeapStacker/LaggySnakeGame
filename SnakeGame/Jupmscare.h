#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "DefineFile.h"
using namespace std;
using namespace sf;
class Jupmscare
{
	Texture scaryTexture;
public:
	RectangleShape jumpScare;
	Jupmscare();
	void changAlpha() {
		jumpScare.setFillColor(Color(255, 255, 255, jumpScare.getFillColor().a + 1));
	}
};

