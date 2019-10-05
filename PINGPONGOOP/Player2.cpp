#include "Player2.h"

Player2::Player2()
{
	PlayerShape.setSize(Vector2f(100, 50));
	PlayerShape.setFillColor(Color::White);
	PlayerShape.setScale(Vector2f(1, 0.2f));
	PlayerShape.setOrigin(Vector2f(PlayerShape.getSize().x / 2, PlayerShape.getSize().y / 2));
	PlayerShape.setRotation(90);
	PlayerShape.setPosition(Vector2f(1920-150,450 ));
	Velocity2 = 0;
}
RectangleShape Player2::getShape()
{
	return PlayerShape;
}
Player2::Player2(VideoMode& mode)
{
	PlayerShape.setSize(Vector2f(100, 50));
	PlayerShape.setFillColor(Color::White);
	PlayerShape.setScale(Vector2f(1, 0.2f));
	PlayerShape.setOrigin(Vector2f(PlayerShape.getSize().x / 2, PlayerShape.getSize().y / 2));
	PlayerShape.setRotation(90);
	PlayerShape.setPosition(Vector2f(mode.width-150, mode.height/2));
	Velocity2 = 0;
}

void Player2::MovementControl2(float DeltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		this->Velocity2 = (Velocity2 - DeltaTime) * 0.3f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		Velocity2 = (Velocity2 + DeltaTime) * 0.3f;
	}
	if (Velocity2 > MaxSpeed)
	{
		Velocity2 = MaxSpeed;
	}
	if (Velocity2 < -MaxSpeed)
	{
		Velocity2 = -MaxSpeed;
	}
	this->PlayerShape.move(0, Velocity2 * DeltaTime);
}
