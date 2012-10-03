/*
Name: ScriptDemo
Date: 04/2008
Description: Demonstrates the use of Lua library
*/
#include "../Engine/msvc10/Advanced2D.h"

using namespace Advanced2D;


#define OBJECT_BORDER 99
#define OBJECT_BACKGROUND 100
#define OBJECT_CHARACTER 1
#define CHARACTER_SPEED 10
#define MAX 50
#define SCALE_OF_TILE 5
#define COL 12 
#define ROW 9
#define TILESIZE 18
#define SCREENW SCALE_OF_TILE * COL * TILESIZE
#define SCREENH SCALE_OF_TILE * ROW * TILESIZE
//Font *font;
//Script script;



int map [ROW][COL];
Sprite *character;
int keypress_arrowkey;
boolean key_release = false; 
boolean win_flag = false;


bool game_preload() 
{


	g_engine->setAppTitle("Tc_Escape_Game");
	g_engine->setFullscreen(false);
	g_engine->setScreenWidth(SCREENW);
	g_engine->setScreenHeight(SCREENH);
	g_engine->setColorDepth(32);    
	memset(map,0,ROW*COL);
	return 1;
}

bool game_init(HWND) 
{



	Sprite *background ;



	for (int i = 0 ; i<ROW ; i++){
		for (int j = 0 ; j< COL  ; j++){
			background = new Sprite();
			//	row = 
			if( i == 0 || i == ROW-1 || j == 0|| j== COL-1){
				background->loadImage("./Resources/Border.bmp");
				background->setObjectType(OBJECT_BORDER);
				background->setCollidable(true);
			}
			else{
				background->loadImage("./Resources/Tiles.bmp");
				background->setObjectType(OBJECT_BACKGROUND);
				background->setCollidable(true);
			}

			map[i][j] = background->getObjectType();

			background->setSize(18,18);
			background->setScale(5);
			background->setPosition(j*TILESIZE*SCALE_OF_TILE,i*TILESIZE*SCALE_OF_TILE);

			g_engine->addEntity(background);
		}
	}





	character = new Sprite();
	character->loadImage("./Resources/character.tga");
	character->setCurrentFrame(0);
	character->setTotalFrames(12);
	character->setColumns(3);
	character->setAnimationDirection(0);
	character->setSize(32,32);
	character->setObjectType(OBJECT_CHARACTER);
	character->setCollidable(true);
	character->setPosition( SCREENW/2-character->getWidth()/2, SCREENH/2-character->getHeight()/2 );
	character->setFrameTimer(60);

	character->setScale(3);
	g_engine->addEntity(character);






	return true;
}

void game_render2d()
{
	std::ostringstream ostr;


}

void game_end() 
{

	///	delete font;
}

void game_keyRelease(int key) 
{ 


	switch (key) {
	case DIK_ESCAPE:
		win_flag = true;
		g_engine->Close();
		break;




	case DIK_DOWN:
	case DIK_LEFT:	
	case DIK_RIGHT:
	case DIK_UP:
		key_release = false;
		if (character->getCurrentFrame() == 0 ||character->getCurrentFrame() == 3 || character->getCurrentFrame() == 6 || character->getCurrentFrame() == 9 ){
			//;

			break;

		}
	} 
	//character->setCurrentFrame(keypress_arrowkey);
}

void game_render3d()
{
	g_engine->ClearScene(D3DCOLOR_XRGB(0,0,80));
}

void game_update() { }
void game_keyPress(int key) { 


	if (key == DIK_DOWN ||key == DIK_LEFT ||key == DIK_RIGHT||key==DIK_UP){
		key_release = true;
		
		switch (key) {

		case DIK_DOWN:

			keypress_arrowkey = 0;
			character->setVelocity(0,CHARACTER_SPEED);

			break;
		case DIK_LEFT:

			keypress_arrowkey = 3;
			character->setVelocity(-CHARACTER_SPEED,0);

			break;
		case DIK_RIGHT:
			character->setVelocity(CHARACTER_SPEED,0);
			keypress_arrowkey = 6;

			break;
		case DIK_UP:
			keypress_arrowkey = 9;
			character->setVelocity(0,-CHARACTER_SPEED);
			break;

		}
		if (character->getCurrentFrame() == 0 ||character->getCurrentFrame() == 3 || character->getCurrentFrame() == 6 || character->getCurrentFrame() == 9 ){
			character->setCurrentFrame(keypress_arrowkey);
			
		}
	}

}
void game_mouseButton(int button) { }
void game_mouseMotion(int x,int y) { }
void game_mouseMove(int x,int y) { }
void game_mouseWheel(int wheel) { }
void game_entityRender(Advanced2D::Entity* entity) { }
void game_entityUpdate(Advanced2D::Entity* entity) {
	Sprite* sprite = (Sprite*)entity;

	if (sprite->getObjectType() == OBJECT_CHARACTER ){
		if  (sprite->getCurrentFrame() == keypress_arrowkey && key_release == true){
			character->setAnimationDirection(1);
		}
		else if  (character->getCurrentFrame() == 0 ||character->getCurrentFrame() == 3 || character->getCurrentFrame() == 6 || character->getCurrentFrame() == 9   && key_release == false){
			character->setAnimationDirection(0);
			character->setVelocity(0,0);
		}
		else if (sprite->getCurrentFrame()  == keypress_arrowkey +  sprite->getColumns() -1){

			sprite->setCurrentFrame(keypress_arrowkey) ;

		}
	}

}
void game_entityCollision(Advanced2D::Entity* entity1,Advanced2D::Entity* entity2) {

	Sprite *a = (Sprite*)entity1;
	Sprite *b = (Sprite*)entity2;

	if (a->getObjectType() == OBJECT_CHARACTER && b->getObjectType() == OBJECT_BORDER)
	{


		double x1 = a->getX();
		double y1 = a->getY();

		double vx1 = a->getVelocity().getX();
		double vy1 = a->getVelocity().getY();
		a->setPosition(x1-vx1,y1-vy1);
	}

}

