#include "Player.h"

/*0 upperwall
1 leftwall
2 bottomwall
3 rightwall
4 midfield

*/
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
	PlayerShape.setSize(Vector2f(mode.width*0.06f, 50));
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

void Player::MovementControl()
{
	Velocity = 2.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		Velocity = Velocity * -6.3f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Velocity = Velocity * 6.3f;
	}

	if (Velocity > 25.0f)
	{
		Velocity = 25.0f;
	}
	if (Velocity < -25.0f)
	{
		Velocity = -25.0f;
	}
	
	PlayerShape.move(0, Velocity);
	
	
}

