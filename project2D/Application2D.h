#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Player.h"
#include "Bullet.h"
#include "Walls.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Texture*		mPlayerTexture;
	aie::Texture*       mBulletTexture;
	aie::Texture*		mTruckTexture;
	aie::Font*			m_font;

	Player *mPlayer;
	Walls *mTruck;

	float m_cameraX, m_cameraY;
	float m_timer;
	float mPx, mPy;
};