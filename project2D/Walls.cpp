#include "Walls.h"

Walls::Walls()
{

}

Walls::~Walls()
{

}

Walls::Walls(Vector2 * position)
{
	mPos = position;
}

Vector2 Walls::Position()
{
	return *mPos;
}
