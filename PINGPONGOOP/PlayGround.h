#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <iterator>
using namespace std;
using namespace sf;
class PlayGround
{
private:
	list<RectangleShape> PlayWall;
public:
	void DisplayPlayGround(RenderWindow &window);
	list<RectangleShape> GetList();
	RectangleShape setWall(float length, float width, float rotation,Color color,float positionx,float positiony,Vector2f scale);
	void CreateWall(VideoMode &mode);
	PlayGround();
	//~PlayGround();

};

