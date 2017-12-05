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
	mBullets = new Bullet[500];
	mNumBullets = 500;
	mCurrentBullet = 0;
	for (int i = 0; i < 500; i++)
	{
		mBullets[i] = Bullet(mPosition, 500, 10);
	}
}

void Player::MovePlayer(float deltaTime, aie::Input *input)
{
	if (input->wasKeyPressed(aie::INPUT_KEY_LEFT)) {
		mRotation = 3.14;
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_RIGHT)) {
		mRotation = 0;
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_UP)) {
		mRotation = 1.57;
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_DOWN)) {
		mRotation = 4.71;
	}
	if (input->isKeyDown(aie::INPUT_KEY_W)){
		if (mPosition->mY <= 850)
			mPosition->mY += mMovespeed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S)){
		if (mPosition->mY >= 50)
			mPosition->mY -= mMovespeed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_A)){
		if(mPosition->mX >= 50)
			mPosition->mX -= mMovespeed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D)){
		if(mPosition->mX <= 1450)
			mPosition->mX += mMovespeed * deltaTime;

	}

		if(mRotation == 0 && input->wasKeyPressed(aie::INPUT_KEY_RIGHT))
			mBullets[mCurrentBullet++].Fire(Vector2(1,0));
		if((mRotation > 1 && mRotation < 2) && input->wasKeyPressed(aie::INPUT_KEY_UP))
			mBullets[mCurrentBullet++].Fire(Vector2(0, 1));
		if ((mRotation > 3 && mRotation < 4) && input->wasKeyPressed(aie::INPUT_KEY_LEFT))
			mBullets[mCurrentBullet++].Fire(Vector2(-1, 0));
		if((mRotation > 4 && mRotation < 5) && input->wasKeyPressed(aie::INPUT_KEY_DOWN))
			mBullets[mCurrentBullet++].Fire(Vector2(0, -1));

	if (mCurrentBullet >= mNumBullets)
		mCurrentBullet = 0;

	for (int i = 0; i < mNumBullets; i++)
	{
		if (!mBullets[i].mIsFired)
			mBullets[i].mPosition = new Vector2(mPosition->mX, mPosition->mY);
		mBullets[i].FireBullet(deltaTime);
	}
	std::cout << mPosition->mY << std::endl;
	std::cout << mPosition->mX << std::endl;
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

