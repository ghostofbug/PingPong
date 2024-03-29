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
	PlayerShape.setSize(Vector2f(mode.width*0.08f, 50));
	PlayerShape.setFillColor(Color::White);
	PlayerShape.setScale(Vector2f(1, 0.2f));
	PlayerShape.setOrigin(Vector2f(PlayerShape.getSize().x / 2, PlayerShape.getSize().y / 2));
	PlayerShape.setRotation(90);
	PlayerShape.setPosition(Vector2f(mode.width-150, mode.height/2));
	Velocity2 = 0;
}

void Player2::MovementControl(RectangleShape &leftbound,RectangleShape &rightbound,double DeltaTime)
{
	Velocity = 0.5;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Velocity = Velocity - 2.3f;
		if (PlayerShape.getGlobalBounds().intersects(leftbound.getGlobalBounds()))
		{
			Velocity = 0;
			PlayerShape.setPosition(PlayerShape.getPosition());
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		Velocity = Velocity + 2.3f;
		if (PlayerShape.getGlobalBounds().intersects(rightbound.getGlobalBounds()))
		{
			Velocity = 0;
			PlayerShape.setPosition(PlayerShape.getPosition());
		}
	}
	if (Velocity > 5.0f)
	{
		Velocity = 5.0f;
	}
	if (Velocity < -5.0f)
	{
		Velocity = -5.0f;
	}
	cout << Velocity << endl;

	PlayerShape.move(0, Velocity * DeltaTime * 5000000);
}

