#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

Bullet::Bullet(Vector2 *position, int movespeed, int damage)
{
	mPosition = position;
	mMovespeed = movespeed;
	mDamage = damage;
}

void Bullet::FireBullet(float deltaTime, aie::Input * input)
{
}
