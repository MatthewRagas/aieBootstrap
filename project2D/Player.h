#pragma once
#include <Vector2.h>
class Player
{
	int mHealth;
	int mMovespeed;
	Vector2 *mPosition;//Player position x,y.
	Vector2 *mForward; //direction character is facing = player position - mouse position.
	Vector2 *mMouse;   //Mouse x,y.

public:
	Player();
	~Player();
	Player(int health, int movepseed, Vector2 *position);
	void MovePlayer(float deltaTime);
	int TakeDamage();
	void Shoot();
	Vector2 Position(Vector2 position);
	void GameOver();
};