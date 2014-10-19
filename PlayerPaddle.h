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

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

private:
	float _velocity;  // -- left ++ right
	float _maxVelocity;
};
