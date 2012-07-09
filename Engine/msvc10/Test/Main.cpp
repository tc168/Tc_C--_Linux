#include <iostream>
#include "..\Advanced2D.h"
bool game_preload()
{
//display engine version in a message box
g_engine->message(g_engine->getVersionText(), "TEST ENGINE");
//return fail to terminate the engine
return true;
}
bool game_init(HWND hwnd){return 0;}
void game_update(){}
void game_end(){}