#pragma once
#include "Player.h"
class Player2:public Player
{
private:
	RectangleShape PlayerShape;
	const float MaxSpeed = 3.0f;
	float Velocity2 = 0;
public:
	Player2();
	RectangleShape getShape();
	Player2(VideoMode &mode);
	void MovementControl(RectangleShape& leftbound, RectangleShape& rightbound, double DeltaTime);
};

