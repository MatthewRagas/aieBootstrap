#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");
	mPlayerTexture = new aie::Texture("./textures/survivor_handgun.png");
	mBulletTexture = new aie::Texture("./textures/bullet.png");
	mTruckTexture = new aie::Texture("./textures/truck.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	//Starting coordinates of Player and bullet*
	mPx = 750;
	mPy = 450;

	//Creation of a player object*
	mPlayer = Player(100, 250, new Vector2(mPx, mPy), 0.0);
	//Creation of walls
	mTruck = new Walls(new Vector2(900, 500));
	//Zombie
	mZombie = Zombie(10, 120, 10,new Vector2(100,100));
	mZombie.SetTargetPosition(mPlayer);
	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use WASD to move Player*
	if(mPlayer.GetHealth() > 0 && m_timer < 300){
		mPlayer.MovePlayer(deltaTime, input);
	}

	//Spawn Zombies
	//Creation of Zombies
	mZombie.SpawnZombie();


	//Player take damage*
	if (input->isKeyDown(aie::INPUT_KEY_Q))
		mPlayer.TakeDamage(10);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	aie::Input* input = aie::Input::getInstance();
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	//Drawing map borders*
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(mTruckTexture,mTruck->mPos->mX, mTruck->mPos->mY, 300, 300, 0.75, 0);

	//Drawing Zombies
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawBox(mZombie.mPos->mX, mZombie.mPos->mY, 50, 50, 0, 0);

	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 850 - 32);
	m_2dRenderer->drawText(m_font, "Arcade Zombies", 0, 850);

	//Draw Bullets*
	for (int i = 0; i < mPlayer.mNumBullets; i++)
	{
		if (mPlayer.mBullets[i].mIsFired)
			m_2dRenderer->setRenderColour(1, 1, 1, 1);
		m_2dRenderer->drawSprite(mBulletTexture, mPlayer.mBullets[i].mPosition->mX, mPlayer.mBullets[i].mPosition->mY,
			5, 5, mPlayer.mRotation);
	}

	// Draw player*
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(mPlayerTexture, mPlayer.Position().mX, mPlayer.Position().mY,
							 80, 80, mPlayer.mRotation);

	//Game Over Text*
	if (mPlayer.GetHealth() <= 0)
	{
		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "You dieded...", 650, 650);
		m_2dRenderer->drawText(m_font, "Press esc to exit", 650, 600);
	}

	//Win condition text*
	if (m_timer >= 300)
	{
		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "You Win!", 650, 650);
		m_2dRenderer->drawText(m_font, "Press esc to exit", 650, 600);
	}

	// done drawing sprites
	m_2dRenderer->end();
}