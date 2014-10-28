#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class SplashScreen
{
public:
	void Show(sf::RenderWindow& window);
	void Show2(sf::RenderWindow& window);
private:
	int a = 0;
};