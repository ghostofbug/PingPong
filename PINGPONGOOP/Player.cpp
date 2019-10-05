#include "Player.h"

Player::Player()
{
	PlayerShape.setSize(Vector2f(100, 50));
	PlayerShape.setFillColor(Color::Blue);
	PlayerShape.setScale(Vector2f(1, 0.2f));
	PlayerShape.setOrigin(Vector2f(PlayerShape.getSize().x / 2, PlayerShape.getSize().y / 2));
	PlayerShape.setRotation(90);
	PlayerShape.setPosition(Vector2f(150, 450));
	Velocity = 0;
}
Player::Player(VideoMode& mode)
{
	PlayerShape.setSize(Vector2f(100, 50));
	PlayerShape.setFillColor(Color::Blue);
	PlayerShape.setScale(Vector2f(1, 0.2f));
	PlayerShape.setOrigin(Vector2f(PlayerShape.getSize().x / 2, PlayerShape.getSize().y / 2));
	PlayerShape.setRotation(90);
	PlayerShape.setPosition(Vector2f(150, mode.height / 2));
	Velocity = 0;
}
Player::~Player()
{
}

RectangleShape Player::getShape()
{
	return PlayerShape;
}

void Player::MovementControl(float DeltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		Velocity = (Velocity - DeltaTime)*1.3f;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		Velocity = (Velocity +DeltaTime) * 1.3f;
	}
	if (Velocity > MaxSpeed)
	{
		Velocity = MaxSpeed;
	}
	if (Velocity < -MaxSpeed)
	{
		Velocity = -MaxSpeed;
	}
	PlayerShape.move(0, Velocity * DeltaTime);
}
