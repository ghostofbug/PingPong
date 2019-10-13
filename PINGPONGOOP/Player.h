#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PlayGround.h"
using namespace sf;
using namespace std;
class Player
{
protected:
	float Velocity;
	RectangleShape PlayerShape;
	const float MaxSpeed = 3.0f;
public:
	Player();
	Player(VideoMode& mode);
	~Player();
	RectangleShape getShape();
	void MovementControl();
	void SetVelocity();
	
};

