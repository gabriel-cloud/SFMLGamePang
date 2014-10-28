#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "gameOptions.h"
#include "GameBall.h"

void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pang!");
	
	PlayerPaddle *player1 = new PlayerPaddle();
	//player1->Load("images/paddle.png");
	player1->SetPosition((SCREEN_WIDTH / 2) - 45, 700);

	GameBall *ball = new GameBall();

	ball->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);

	//GameBall *ball1 = new GameBall();

	//ball1->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);

	//_gameObjectManager.Add("Ball1", ball1);

	//GameBall *ball2 = new GameBall();

	//ball2->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);

	//_gameObjectManager.Add("Ball2", ball2);

	_gameObjectManager.Add("Paddle1", player1);
	_gameObjectManager.Add("Ball", ball);

	_gameState = Game::ShowingSplash;


	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

const GameObjectManager& Game::GetGameObjectManager()
{
	return Game::_gameObjectManager;
}

sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

const sf::Event& Game::GetInput()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
	return currentEvent;
}

void Game::GameLoop()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);


	switch (_gameState)
	{
	case Game::ShowingMenu:
	{
							  ShowMenu();
							  break;
	}
	case Game::ShowingSplash:
	{
								ShowSplashScreen();
								break;
	}
	case Game::Playing:
	{
						  _mainWindow.clear(sf::Color(0, 0, 0));

						  _gameObjectManager.UpdateAll();
						  _gameObjectManager.DrawAll(_mainWindow);

						  _mainWindow.display();
						  if (currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;

						  if (currentEvent.type == sf::Event::KeyPressed)
						  {
							  if (currentEvent.key.code == sf::Keyboard::Escape) ShowMenu();
						  }

						  break;
	}
	}
}

void Game::ShowSplashScreen()
 {
	   SplashScreen splashScreen;
	   SplashScreen splashScreen2;

	   splashScreen.Show(_mainWindow);
	   splashScreen2.Show2(_mainWindow);

	   _gameState = Game::ShowingMenu;
 }

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		_gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		_gameObjectManager.ResetClock();
		_gameState = Game::Playing;
		break;
	case MainMenu::Options:
		_gameState = Game::Options;
	}
}

void Game::gOptions()
{
	GameOptions optionsMenu;
	optionsMenu.ShowOptions(_mainWindow);
	_gameState = Game::ShowingMenu;
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;