#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{

	//Load menu image from file
	sf::Texture image;
	image.loadFromFile("images/pongmenu.png");
	sf::Sprite sprite(image);

	//Setup clickable regions
	//test
	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.width = 300;
	playButton.rect.height = 300;
	playButton.rect.left = 0;
	playButton.rect.top = 250;

	playButton.action = Play;

	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.width = 900;
	exitButton.rect.height = 300;
	exitButton.rect.left = 0;
	exitButton.rect.top = 350;

	exitButton.action = Exit;

	//Options menu item coordinates
	MenuItem optionsButton;
	exitButton.rect.width = 600;
	exitButton.rect.height = 300;
	exitButton.rect.left = 0;
	exitButton.rect.top = 450;
	exitButton.action = Options;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);
	_menuItems.push_back(optionsButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.width > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.height > x)
		{
			return (*it).action;
		}
	}

	return Nothing;
}

MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (42 != 43)
	{

		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}

	}
}