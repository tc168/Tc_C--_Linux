#include "..\Advanced2D.h"

using namespace Advanced2D;
Sprite *sprite;
bool game_preload()
{
	g_engine->setAppTitle("SPRITE COLOR KEY DEMO");
	g_engine->setFullscreen(false);
	g_engine->setScreenWidth(640);
	g_engine->setScreenHeight(480);
	g_engine->setColorDepth(32);
	return 1;
}
bool game_init(HWND)
{
	//load sprite
	sprite = new Sprite();
	sprite->loadImage("explosion_30_128.tga");

sprite->setTotalFrames(30);
sprite->setColumns(6);
sprite->setSize(128,128);
sprite->setFrameTimer(40);
	return true;
}
void game_update()
{
	sprite->animate();
	//exit when escape key is pressed
	//if (KEY_DOWN(VK_ESCAPE)) g_engine->Close();
}
void game_end()
{
	delete sprite;
}
void game_render3d()
{
	g_engine->ClearScene(D3DCOLOR_XRGB(0,0,80));
	g_engine->SetIdentity();
}
void game_render2d()
{
	//calculate center of screen
	int cx = g_engine->getScreenWidth() / 2;
	int cy = g_engine->getScreenHeight() / 2;
	//calculate center of sprite
	int sx = sprite->getWidth() / 2;
	int sy = sprite->getHeight() / 2;
	//draw sprite centered
	sprite->setPosition(cx-sx,cy-sy);
	sprite->draw();
}