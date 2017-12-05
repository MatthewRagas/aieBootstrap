#pragma once
#include<Vector2.h>
class Walls
{
public:
	Vector2 *mPos;
	Walls();
	~Walls();
	Walls(Vector2* positioin);
	Vector2 Position();
};
