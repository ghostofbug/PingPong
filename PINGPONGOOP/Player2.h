#pragma once
#include "Player.h"
class Player2 :public Player
{
public:
	Player2();
	Player2(VideoMode &mode);
	void MovementControl2(float DeltaTime);
};

