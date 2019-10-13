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
	Time time1;
	Clock time2;
	VideoMode mode(1920, 1080);
	//mode = VideoMode::getDesktopMode();
	RenderWindow window(mode, "TEST");
	window.setFramerateLimit(60);
	PlayGround playground;
	Event event;
	cout << "nhap esc de thoat" << endl;
	Player player1(mode);
	Player2 player2(mode);
	list<RectangleShape>::iterator i;
	for (i = playground.GetList().begin(); i != playground.GetList().end(); i++)
	{

	}
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
			{
				window.close();
				break;
			}

			case Event::KeyPressed:
			{
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					window.close();
				}
				if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S))
				{
					player1.MovementControl();
				}
				if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Down))
				{
					player2.MovementControl();
				}
				break;
			}
			}
		}
		window.clear();
		window.draw(player1.getShape());
		window.draw(player2.getShape());
		playground.CreateWall(mode);
		playground.DisplayPlayGround(window);
		window.display();
	}
}