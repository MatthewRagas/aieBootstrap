#include "Zombies.h"


Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

Zombie::Zombie(int damage, int speed, int life, Vector2 * pos)
{
	mDamage = damage;
	mWalkSpeed = speed;
	mLife = life;
	mPosition = pos;
}

//Spawns zombies every 30 seconds
void Zombie::SpawnZombie()
{
}

//Zombie spawns and begins to walk to and follow the player position each frame
void Zombie::ZombieWalk(float deltaTime)
{
	Vector2* distance = new Vector2(mPosition->mX - mPlayerPos->mPosition->mX,
									mPosition->mY - mPlayerPos->mPosition->mY);
	if (distance->mX > 1)
		distance->mX -= 120 * deltaTime;
	if (distance->mX < -1)
		distance->mX += 120 * deltaTime;
	if (distance->mY > 1)
		distance->mY -= 120 * deltaTime;
	if (distance->mY < -1)
		distance->mY += 120 * deltaTime;

}

void Zombie::DoDamage()
{
}

int Zombie::GetDamage()
{
	return 0;
}

int Zombie::TakeDamage()
{
	return 0;
}

int Zombie::GetLife()
{
	return 0;
}
