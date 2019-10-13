#include<SFML/Graphics.hpp>
#include<iostream>
#include "Player.h"
#include "PlayGround.h"
#include "Player2.h"
using namespace std;
using namespace sf;
int main()
{
	Clock time;
	Time elapsedtime;
	VideoMode mode(800, 450);
	//mode = VideoMode::getDesktopMode();
	RenderWindow window(mode, "TEST");
	window.setFramerateLimit(0);
	PlayGround playground;
	Event event;
	cout << "nhap esc de thoat" << endl;
	Player player1(mode);
	Player2 player2(mode);
	window.setKeyRepeatEnabled(false);
	while (window.isOpen())
	{
		
		elapsedtime = time.getElapsedTime();
		if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S))
		{
			player1.MovementControl(playground.GetList().at(0), playground.GetList().at(2),elapsedtime.asSeconds());
		}
		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Down))
		{
			player2.MovementControl(playground.GetList().at(0), playground.GetList().at(2), elapsedtime.asSeconds());
		}
		while (window.pollEvent(event))
		{	
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					window.close();
				}
				
		}
		window.clear();
		window.draw(player1.getShape());
		window.draw(player2.getShape());
		playground.CreateWall(mode);
		playground.DisplayPlayGround(window);
		window.display();
		elapsedtime = time.restart();
	}
}