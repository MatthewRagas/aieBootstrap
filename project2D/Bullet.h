#pragma once
#include <Vector2.h>
#include<Input.h>

class Bullet
{
public:
	Vector2 *mPosition;
	int mMovespeed;
	int mDamage;
	Bullet();
	~Bullet();
	Bullet(Vector2 *position, int movespeed, int damage);
	void FireBullet(float deltaTime, aie::Input *input);
};