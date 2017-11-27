#include "Player.h"

Player::Player()
{
	mHealth = 100;
	mMovespeed = 20;
	mPosition = new Vector2();
}

Player::Player(int health, int movespeed, Vector2 *position)
{
	mHealth = health;
	mMovespeed = movespeed;
	mPosition = position;
}

void Player::MovePlayer(char movespeed)
{

}

int Player::TakeDamage(int health)
{
	return 0;
}

void Player::Shoot()
{
}

Vector2 Player::Position(Vector2 position)
{
	return Vector2();
}
