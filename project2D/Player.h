#pragma once
#include <Vector2.h>
class Player
{
	int mHealth;
	int mMovespeed;
	Vector2 *mPosition;

public:
	Player();
	Player(int health, int movepseed, Vector2 *position);
	void MovePlayer(char movespeed);
	int TakeDamage(int health);
	void Shoot();
	Vector2 Position(Vector2 position);
};