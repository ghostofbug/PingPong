#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(300, 300), "TEST");
	RectangleShape rec(Vector2f(100, 200));
	rec.setFillColor(Color::Green);
	Event event;
	cout << "nhap esc de thoat" << endl;
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
		}
		window.clear();
		window.draw(rec);
		window.display();
	}
}