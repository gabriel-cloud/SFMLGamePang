#pragma once
#include "stdafx.h"
#include "PlayerPaddle.h"

class Game
{

public:
	static void Start();

private:
	static bool IsExiting();
	static void GameLoop();


	static void ShowSplashScreen();
	static void ShowMenu();
	static void gOptions();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting, Options
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static PlayerPaddle _player1;
};
