#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "SFML//Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace std;
using namespace sf;
static class HelpTools
{
public:
	static Color&& createNewColor() {
		srand(time(0));
		unsigned r = rand() % 256;
		unsigned g = rand() % 256;
		unsigned b = rand() % 256;
		return Color(r, g, b, 255);
	}
};

