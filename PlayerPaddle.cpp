#include "stdafx.h"
#include "PlayerPaddle.h"
#include "Game.h"

PlayerPaddle::PlayerPaddle() :
_velocity(750),
_maxVelocity(1000.0f)
{
	Load("images/paddle.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getLocalBounds().width/ 2, GetSprite().getLocalBounds().height / 2);
}


PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}

float PlayerPaddle::GetVelocity() const
{
	return _velocity;
}

void PlayerPaddle::Update(float elapsedTime) //Few changes here to change movement to something a bit nicer
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//_velocity -= 3.0f;
		GetSprite().move(-_velocity * elapsedTime, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		//_velocity += 3.0f;
		GetSprite().move(_velocity * elapsedTime, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_velocity = 0.0f;
	}

	if (_velocity > _maxVelocity) //Not needed but not commented out yet
		_velocity = _maxVelocity;

	if (_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;


	sf::Vector2f pos = this->GetPosition();

	if (pos.x  <= GetSprite().getLocalBounds().width / 2 //I'd like to clamp the shape ideally, this just stops it moving out of bounds for now.
		|| pos.x >= (Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width / 2))
	{
		_velocity = -_velocity;
	}

//	GetSprite().move(_velocity * elapsedTime, 0);
}