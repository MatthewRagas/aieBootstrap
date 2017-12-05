#include "Player.h"
#include <math.h>
#include<Font.h>
#include"Renderer2D.h"


Player::Player()
{
}

Player::~Player()
{
}

Player::Player(int health, int movespeed, Vector2 *position, float rotation)
{
	mHealth = health;
	mMovespeed = movespeed;
	mPosition = position;
	mRotation = rotation;

}

void Player::MovePlayer(float deltaTime, aie::Input *input)
{
	if (input->isKeyDown(aie::INPUT_KEY_W))
		mPosition->mY += mMovespeed * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_S))
		mPosition->mY -= mMovespeed * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_A))
		mPosition->mX -= mMovespeed * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_D))
		mPosition->mX += mMovespeed * deltaTime;



}

void Player::TakeDamage(int amount)
{
	mHealth -= amount;
}

int Player::GetHealth()
{
	return mHealth;
}

Vector2 Player::PositionForward()
{

	return Vector2();
}

Vector2 Player::Position()
{
	return *mPosition;
}

