#include<SFML/Graphics.hpp>
#include<SFML/Main.hpp>
#include<iostream>
#include <time.h>
#include <cmath>
#include "Player.h"
#include "PlayGround.h"
#include "Ball.h"

#include "Game.h"
using namespace std;
using namespace sf;


void main()
{
	Game game;// tạo object game 
	game.RunEntireGame();// chạy game
	
}