#include "..\Advanced2D.h"

using namespace Advanced2D;
//macro to read the keyboard asynchronously
#define KEY_DOWN(vk) ((GetAsyncKeyState(vk) & 0x8000)?1:0)
//game objects
Camera *camera;
Light *light;
Mesh *mesh;
bool game_preload()
{
g_engine->setAppTitle("LIGHTING DEMO");
g_engine->setFullscreen(false);
g_engine->setScreenWidth(1024);
g_engine->setScreenHeight(768);
g_engine->setColorDepth(32);
return true;
}
bool game_init(HWND){
	//set the camera and perspective
camera = new Camera();
camera->setPosition(0.0f, 2.0f, 40.0f);
camera->setTarget(0.0f, 0.0f, 0.0f);
camera->Update();
//load the mesh
mesh = new Mesh();
mesh->Load("cytovirus.x");
mesh->SetScale(0.1f,0.1f,0.1f);
//create a directional light
D3DXVECTOR3 pos(0.0f,0.0f,0.0f);
D3DXVECTOR3 dir(0.0f,-1.0f,0.0f);
/*D3DLIGHT_DIRECTIONAl;
D3DLIGHT_FORCE_DWORD
D3DLIGHT_POINT
D3DLIGHT_SPOT*/
light = new Light(0, D3DLIGHT_DIRECTIONAL, pos, dir, 100);
//set a low ambient level
g_engine->SetAmbient(D3DCOLOR_XRGB(20,20,20));
return true;
}
void game_update()
{
//rotate the cytovirus mesh
mesh->Rotate(-0.1f,0.0f,0.05f);
//exit when escape key is pressed
if (KEY_DOWN(VK_ESCAPE)) g_engine->Close();
}
void game_end()
{
delete camera;
delete light;
delete mesh;
}
void game_render3d()
{
g_engine->ClearScene(D3DCOLOR_XRGB(0,0,80));
g_engine->SetIdentity();
mesh->Transform();

{
g_engine->ClearScene(D3DCOLOR_XRGB(0,0,80));
g_engine->SetIdentity();
mesh->Transform();
mesh->Draw();
}
}