#include "PlayGround.h"

void PlayGround::DisplayPlayGround(RenderWindow &window)
{
	list<RectangleShape>::iterator i;
	for (i = PlayWall.begin(); i != PlayWall.end(); i++)
	{
		window.draw(*i);
	}
}

list<RectangleShape> PlayGround::GetList()
{
	return PlayWall;
}

RectangleShape PlayGround::setWall(float length, float width, float rotation,Color color,float positionx,float positiony,Vector2f scale)
{
	RectangleShape rec;
	rec.setOrigin(Vector2f(length / 2, width / 2));
	rec.setSize(Vector2f(length, width));
	rec.setRotation(rotation);
	rec.setPosition(positionx, positiony);
	rec.setFillColor(color);
	rec.setScale(scale);
	return rec;
}

void PlayGround::CreateWall(VideoMode &mode)
{
	RectangleShape midfield = setWall(static_cast<float>(mode.height*2), static_cast<float>(mode.width), 90, Color::Red, static_cast<float>(mode.width)/2, 0, Vector2f(1, 0.01f));
	RectangleShape upperwall = setWall(static_cast<float>(mode.height*2), static_cast<float>(mode.width),0, Color::Yellow, static_cast<float>(mode.height), 0,Vector2f(1,0.01f));
	RectangleShape bottomwall = setWall(static_cast<float>(mode.height * 2), static_cast<float>(mode.width), 0, Color::Yellow, static_cast<float>(mode.height), static_cast<float>(mode.height), Vector2f(1, 0.01f));
	RectangleShape rightwall = setWall(static_cast<float>(mode.height*2), static_cast<float>(mode.width*0.1f), 90, Color::Yellow, mode.height*0.08f, 0,Vector2f(1,0.05f));
	RectangleShape leftwall = setWall(static_cast<float>(mode.height * 2), static_cast<float>(mode.width * 0.1f), 90, Color::Yellow, mode.height * 1.7f , 0, Vector2f(1, 0.05f));
	//RectangleShape bottomwall = setWall(mode.height, mode.width, 180, Color::Yellow, mode.height,mode.width,Vector2f(1,0.05f));
	//RectangleShape rightwall = setWall(mode.height, mode.width, 90, Color::Yellow, 0, mode.width, Vector2f(1, 0.05f));
	PlayWall.push_back(upperwall);
	PlayWall.push_back(leftwall);
	PlayWall.push_back(bottomwall);
	PlayWall.push_back(rightwall);
	PlayWall.push_back(midfield);

}

PlayGround::PlayGround()
{
	//CreateWall();
}
