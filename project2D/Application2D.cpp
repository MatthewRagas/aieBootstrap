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

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	mPx = 750;
	mPy = 450;


	mPlayer = new Player(100, 250, new Vector2(mPx, mPy), 0.0f);
	mBullet = new Bullet(new Vector2(mPx,mPy),500,0);
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

	// use arrow keys to move camera
	if (input->wasKeyPressed(aie::INPUT_KEY_LEFT)){
		mPlayer->mRotation = 3.14f;

	}
	if (input->wasKeyPressed(aie::INPUT_KEY_RIGHT)){
		mPlayer->mRotation = 0.00f;

	}
	if (input->wasKeyPressed(aie::INPUT_KEY_UP)){
		mPlayer->mRotation = 1.57f;

	}
	if (input->wasKeyPressed(aie::INPUT_KEY_DOWN)){
		mPlayer->mRotation = 4.81f;
		mBullet->mPosition->mY -= 200.00 * deltaTime;
	}

	//if (input->isKeyDown(aie::INPUT_KEY_A))
	//	m_cameraX -= 550.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_D))
	//	m_cameraX += 550.0f * deltaTime;

	// use WASD to move Player
	if(mPlayer->GetHealth() > 0 && m_timer < 300)
		mPlayer->MovePlayer(deltaTime, input);

	//Player take damage
	if (input->isKeyDown(aie::INPUT_KEY_Q))
		mPlayer->TakeDamage(10);

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



	// demonstrate animation
	/*m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);*/

	/* demonstrate spinning sprite*/
	/*m_2dRenderer->setUVRect(0,0,1,1);
	m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);*/

	// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);//

	// draw a moving purple circle
	/*m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);*/

	// draw a rotating red box
	/*m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);*/

	// draw a slightly rotated sprite with no texture, coloured yellow
	/*m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);*/

	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 850 - 32);
	m_2dRenderer->drawText(m_font, "Arcade Zombies", 0, 850);
	m_2dRenderer->drawText(m_font, "Press esc to quit", 1200, 850);

	//Draw bullet
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(mBulletTexture, mBullet->mPosition->mX, mBullet->mPosition->mY,
		5, 5, mPlayer->mRotation);

	// Draw player
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(mPlayerTexture, mPlayer->Position().mX, mPlayer->Position().mY,
							 80, 80, mPlayer->mRotation);



	//float mag = mPlayer->PositionForward().Magnitude() * mPlayer->Position().Magnitude();
	//float angle = mPlayer->Position().Dot(mPlayer->PositionForward()) / mag;
	//*std::cout << angle << std::endl;*/
	//*mag *= -1;*/


	//Draw Mouse


	//Game Over Text
	if (mPlayer->GetHealth() <= 0)
	{
		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "You dieded...", 650, 650);
		m_2dRenderer->drawText(m_font, "Press esc to exit", 650, 600);
		m_2dRenderer->drawText(m_font, "or", 650, 550);
		m_2dRenderer->drawText(m_font, "press Space to restart.", 650, 500);
	}

	//Win condition text
	if (m_timer >= 300)
	{
		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "You Win!", 650, 650);
		m_2dRenderer->drawText(m_font, "Press esc to exit", 650, 600);
		m_2dRenderer->drawText(m_font, "or", 650, 550);
		m_2dRenderer->drawText(m_font, "press Space to restart.", 650, 500);
	}

	// done drawing sprites
	m_2dRenderer->end();
}