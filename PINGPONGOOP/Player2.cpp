#include "Player2.h"

Player2::Player2()
{
	PlayerShape.setSize(Vector2f(100, 50));
	PlayerShape.setFillColor(Color::White);
	PlayerShape.setScale(Vector2f(1, 0.2f));
	PlayerShape.setOrigin(Vector2f(PlayerShape.getSize().x / 2, PlayerShape.getSize().y / 2));
	PlayerShape.setRotation(90);
	PlayerShape.setPosition(Vector2f(1920-150,450 ));
	Velocity = 0;
}
Player2::Player2(VideoMode& mode)
{
	PlayerShape.setSize(Vector2f(100, 50));
	PlayerShape.setFillColor(Color::White);
	PlayerShape.setScale(Vector2f(1, 0.2f));
	PlayerShape.setOrigin(Vector2f(PlayerShape.getSize().x / 2, PlayerShape.getSize().y / 2));
	PlayerShape.setRotation(90);
	PlayerShape.setPosition(Vector2f(mode.width-150, mode.height/2));
	Velocity = 0;
}

void Player2::MovementControl2(float DeltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		Velocity = (Velocity - DeltaTime) * 1.2f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		Velocity = (Velocity + DeltaTime) * 1.2f;
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
