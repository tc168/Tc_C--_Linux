/*
Name: ScriptDemo
Date: 04/2008
Description: Demonstrates the use of Lua library
*/
#include "../Engine/msvc10/Advanced2D.h"

using namespace Advanced2D;


#define OBJECT_BACKGROUND 99
#define CHARCTER_DOWN 1
#define CHARCTER_LEFT 2
#define CHARCTER_RIGHT 3
#define CHARCTER_UP 4
#define OBJECT_SPRITE 100
#define MAX 50
#define SCALE_OF_TILE 5
#define COL 12 
#define ROW 9
#define TILESIZE 18
#define SCREENW SCALE_OF_TILE * COL * TILESIZE
#define SCREENH SCALE_OF_TILE * ROW * TILESIZE
//Font *font;
//Script script;

std::string title;
int width;
int height;
int depth;
bool fullscreen;
Texture* Tile;
int map [ROW][COL];
Sprite *character;


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
			}
			else{
				background->loadImage("./Resources/Tiles.bmp");
			}
			background->setObjectType(OBJECT_BACKGROUND);

			background->setSize(18,18);

			background->setScale(5);
			background->setPosition(j*TILESIZE*SCALE_OF_TILE,i*TILESIZE*SCALE_OF_TILE);
			//background->
			g_engine->addEntity(background);
			//}
		}
	}

	

	char buff[50];

	 character = new Sprite();

	 character->setObjectType(CHARCTER_DOWN);
	
	 sprintf(buff,"./Resources/character_%i.tga",character->getObjectType());

    

	character->loadImage(buff);
	 character->setTotalFrames(3);
	  character->setColumns(3);
	   character->setSize(32,32);
    character->setPosition( 10, SCREENH/2-character->getHeight()/2 );
	// character->setFrameTimer( rand() % 100 );
      //  character->setCurrentFrame( rand() % 64 );
		character->setScale(3);
    g_engine->addEntity(character);






	/*//load the Verdana10 font
	font = new Font();
	if (!font->loadImage("verdana10.tga")) {
	g_engine->message("Error loading verdana10.tga");
	return false;
	}
	if (!font->loadWidthData("verdana10.dat")) {
	g_engine->message("Error loading verdana10.dat");
	return false;
	}
	font->setColumns(16);
	font->setCharSize(20,16);
	*/
	return true;
}

void game_render2d()
{
	std::ostringstream ostr;

	/*	font->Print(10,20,title);

	ostr << "Screen Width: " << width;
	font->Print(10,40,ostr.str());

	ostr.str("");
	ostr << "Screen Height: " << height;
	font->Print(10,60,ostr.str());

	ostr.str("");
	ostr << "Color Depth: " << depth;
	font->Print(10,80,ostr.str());

	ostr.str("");
	ostr << "Fullscreen: " << fullscreen;
	font->Print(10,100,ostr.str());
	*/
}

void game_end() 
{

	///	delete font;
}

void game_keyRelease(int key) 
{ 
	switch (key) {
	case DIK_ESCAPE:
		g_engine->Close();
		break;
	}
}

void game_render3d()
{
	g_engine->ClearScene(D3DCOLOR_XRGB(0,0,80));
}

void game_update() { }
void game_keyPress(int key) { 

}
void game_mouseButton(int button) { }
void game_mouseMotion(int x,int y) { }
void game_mouseMove(int x,int y) { }
void game_mouseWheel(int wheel) { }
void game_entityRender(Advanced2D::Entity* entity) { }
void game_entityUpdate(Advanced2D::Entity* entity) { }
void game_entityCollision(Advanced2D::Entity* entity1,Advanced2D::Entity* entity2) { }
