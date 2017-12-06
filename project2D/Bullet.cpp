#include "Bullet.h"
#include "Input.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

Bullet::Bullet(Vector2 *position, int movespeed, int damage)
{
	mPosition = new Vector2(position->mX, position->mY);
	mMovespeed = movespeed;
	mDamage = damage;
	mIsFired = false;
}

void Bullet::FireBullet(float deltaTime)
{
	if (!mIsFired)
		return;

	*mPosition = *mPosition + *mDirection * mMovespeed * deltaTime;
}

void Bullet::Fire(Vector2 dir, Vector2 orgin)
{
	mIsFired = true;
	mPosition = new Vector2(orgin.mX, orgin.mY);
	mDirection = new Vector2(dir.mX, dir.mY);
}