#pragma once
#include <Vector2.h>
#include"Input.h"
class Player
{
	int mHealth;
	int mMovespeed;
	//Player position x,y.
	 //direction character is facing = player position - mouse position.

public:
	Vector2 *mPosition;
	float mRotation;
	Vector2 *mMouse;   //Mouse x,y.
	Player();
	~Player();
	Player(int health, int movepseed, Vector2 *position, float rotation);
	void MovePlayer(float deltaTime, aie::Input *input);
	void TakeDamage(int amount);
	int GetHealth();
	Vector2 PositionForward();
	Vector2 Position();
};