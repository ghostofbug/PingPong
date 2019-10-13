#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <iterator>
#include <vector>
using namespace std;
using namespace sf;
class PlayGround
{
private:
	vector<RectangleShape> PlayWall;
public:
	void DisplayPlayGround(RenderWindow &window);
	vector<RectangleShape> GetList();
	RectangleShape setWall(float length, float width, float rotation,Color color,float positionx,float positiony,Vector2f scale);
	void CreateWall(VideoMode &mode);
	PlayGround();
	//~PlayGround();

};

