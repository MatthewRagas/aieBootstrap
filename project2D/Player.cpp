#include "Player.h"
#include"Input.h"


Player::Player()
{
	mHealth = 100;
	mMovespeed = 20;
	mPosition = new Vector2();
}

Player::~Player()
{
}

Player::Player(int health, int movespeed, Vector2 *position)
{
	mHealth = health;
	mMovespeed = movespeed;
	mPosition = position;
}

void Player::MovePlayer(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	
	if (input->isKeyDown(aie::INPUT_KEY_W))
		mPosition->mY += 480.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_S))
		mPosition->mY += 480.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_A))
		mPosition->mX += 480.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_D))
		mPosition->mX += 480.0f * deltaTime;
		
}

int Player::TakeDamage()
{
	mHealth -= 10;
	return mHealth;
}

void Player::Shoot()
{
}

Vector2 Player::Position(Vector2 position)
{
	return Vector2();
}
