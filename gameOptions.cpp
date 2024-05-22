#include "stdafx.h"
#include "MainMenu.h"
#include "gameOptions.h"
#include "Game.h"

//write proper code here sometime
void GameOptions::ShowOptions(sf::RenderWindow& window)
{

	window.clear(sf::Color::Black);
	window.display();

	sf::Event optionsEvent;
	while (window.pollEvent(optionsEvent))
	{
		if (optionsEvent.type == sf::Event::MouseButtonPressed)
		{
			return;
		}
	}
}

//asdasd