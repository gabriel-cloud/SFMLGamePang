#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
	sf::Texture image;
	if (image.loadFromFile("Images/JonSoft.png") != true)
	{
		return;
	}

	sf::Sprite sprite(image);
//	renderWindow.draw(sprite);
//	renderWindow.display();
	renderWindow.setFramerateLimit(60);
	sf::Event event;

	while (true)
	{
		//Below we have an attempt at fading in the image, if this fucks things up uncomment above and comment this, seems to slow compilation..
		if (a < 255){
			sprite.setColor(sf::Color(255, 255, 255, a));
			a++;
			if (a == 255) return;
		}

		renderWindow.clear(sf::Color::Black);
		renderWindow.draw(sprite);
		renderWindow.display();

	}
}

void SplashScreen::Show2(sf::RenderWindow & renderWindow)
{
	sf::Texture image;
	if (image.loadFromFile("Images/Kenny.png") != true)
	{
		return;
	}

	sf::Sprite sprite(image);
	//	renderWindow.draw(sprite);
	//	renderWindow.display();
	renderWindow.setFramerateLimit(60);
	sf::Event event;

	while (true)
	{
		//Below we have an attempt at fading in the image, if this fucks things up uncomment above and comment this, seems to slow compilation..
		if (a < 255){
			sprite.setColor(sf::Color(255, 255, 255, a));
			a++;
			if (a == 255) return;
		}

		renderWindow.clear(sf::Color::Black);
		renderWindow.draw(sprite);
		renderWindow.display();
	}
}