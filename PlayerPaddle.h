#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "VisibleGameObject.h"

class PlayerPaddle :
	public VisibleGameObject
{
public:
	PlayerPaddle();
	~PlayerPaddle();

};
