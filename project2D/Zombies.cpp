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
	mPos = pos;
	mIsSpawned = false;
}

//Spawns zombies every 30 seconds
void Zombie::SpawnZombie()
{
	int amount = 500;
	Zombie zombies[500];
	for (int i = 0; i < amount; i++)
	{
		zombies[i] = *new Zombie(10, 120, 10, mPos);
	}
	mIsSpawned = true;
}

//Zombie spawns and begins to walk to and follow the player position each frame
void Zombie::ZombieWalk(Vector2 dir)
{
	mDir = new Vector2(dir.mX, dir.mY);
}

void Zombie::DoDamage()
{
}

void Zombie::SetTargetPosition(Player& player)
{
	mPos = player.mPosition;
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
