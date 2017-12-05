#pragma once
#include <Vector2.h>
#include<Input.h>

class Bullet
{
public:
	Vector2 *mPosition;
	Vector2 *mDirection;
	bool mIsFired;
	int mMovespeed;
	int mDamage;
	Bullet();
	~Bullet();
	Bullet(Vector2 *position, int movespeed, int damage);
	void FireBullet(float deltaTime);
	void Fire(Vector2 dir);
};