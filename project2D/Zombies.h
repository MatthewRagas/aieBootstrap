#pragma once
#include <Vector2.h>
#include "Player.h"
class Zombie
{
public:
	int mDamage;
	int mWalkSpeed;
	int mLife;
	Vector2* mPosition;
	Player *mPlayerPos;
	Zombie();
	~Zombie();
	Zombie(int damage, int speed, int life, Vector2 * pos);
	void SpawnZombie();
	void ZombieWalk(float deltaTime);
	void DoDamage();
	int GetDamage();
	int TakeDamage();
	int GetLife();
};