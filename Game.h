#pragma once
#include "stdafx.h"
#include "PlayerPaddle.h"
#include "GameObjectManager.h"

class Game
{

public:
	static void Start();
	static sf::RenderWindow& GetWindow();
	const static sf::Event& GetInput();
	const static GameObjectManager& GetGameObjectManager();

	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

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
	static GameObjectManager _gameObjectManager;
};
//  akusdnkjandjkandkjasd