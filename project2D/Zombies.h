#pragma once
#include <Vector2.h>
#include "Player.h"
class Zombie
{
public:
	int mDamage;
	int mWalkSpeed;
	int mLife;
	bool mIsSpawned;
	Vector2* mPos;
	Vector2* mDir;
	Vector2* mDirection;
	Vector2* mTargetPos;
	Zombie();
	~Zombie();
	Zombie(int damage, int speed, int life, Vector2 * pos);
	void SpawnZombie();
	void ZombieWalk(Vector2 dir);
	void DoDamage();
	void SetTargetPosition(Player& player);
	int GetDamage();
	int TakeDamage();
	int GetLife();
};