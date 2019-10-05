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
	Clock time2;
	VideoMode mode(1920,1080);
	mode = VideoMode::getDesktopMode();
	RenderWindow window(mode, "TEST",Style::Fullscreen);
	window.setFramerateLimit(60);
	PlayGround playground;
	Event event;
	cout << mode.height << endl;
	cout << "nhap esc de thoat" << endl;
	Player player1(mode);
	Player2 player2(mode);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			//if (Keyboard::isKeyPressed(Keyboard::W))
			//{

			//	mode.height = 800;
			//	mode.width = 600;
			//	window.close();
			//	window.create(mode,"TEST");
			//}
			player1.MovementControl(time.getElapsedTime().asSeconds());
			player2.MovementControl2(time2.getElapsedTime().asSeconds());
		}
		window.clear();
		window.draw(player1.getShape());
		window.draw(player2.getShape());
		playground.CreateWall(mode);
		playground.DisplayPlayGround(window);
		window.display();
	}
}