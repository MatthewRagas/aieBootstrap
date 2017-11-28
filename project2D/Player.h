#pragma once
#include <Vector2.h>
#include"Input.h"
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
	void MovePlayer(float deltaTime, aie::Input *input);
	void TakeDamage(int amount);
	int GetHealth();
	void Shoot();
	Vector2 Position();
	void GameOver();
};