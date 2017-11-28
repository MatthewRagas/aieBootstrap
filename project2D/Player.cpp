#include "Player.h"

#include<Font.h>
#include"Renderer2D.h"


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

void Player::MovePlayer(float deltaTime, aie::Input *input)
{	
	if (input->isKeyDown(aie::INPUT_KEY_W))
		mPosition->mY += 480.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_S))
		mPosition->mY -= 480.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_A))
		mPosition->mX -= 480.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_D))
		mPosition->mX += 480.0f * deltaTime;
		
}

void Player::TakeDamage(int amount)
{	
	mHealth -= amount;
}

int Player::GetHealth()
{
	return mHealth;
}

void Player::Shoot()
{
}

Vector2 Player::Position()
{

	return *mPosition;
}

void Player::GameOver()
{
	aie::Font* m_font = new aie::Font("./font/consolas.ttf", 32);
	aie::Renderer2D* m_2dRenderer = new aie::Renderer2D();
	m_2dRenderer->drawText(m_font, "You dieded.\n", 0, 720 - 64);
}
