
#include "Advanced2D.h"

namespace Advanced2D {
	
	Console::Console() 
	{
		showing = false;
		currentLine = 0;
		clear();
	}

	Console::~Console() 
	{
		delete font;
		delete panel;
	}

	bool Console::init()
	{
		//load the panel image
		panel = new Sprite();
		if (!panel->loadImage("panel.tga")) return false;
		double scale = g_engine->getScreenWidth() / 640.0f;
		panel->setPosition(0, g_engine->getScreenHeight()/2);
		panel->setScale(scale);
		panel->setColor(0x99FFFFFF);

		//load the font
		font = new Font();
		//font->setPosition(0, g_engine->getScreenHeight()/2);
		if (!font->loadImage("system12.tga")) return false;
		font->setColumns(16);
		font->setCharSize(14,16);
		if (!font->loadWidthData("system12.dat")) return false;
		

		return true;
	}
	
	void Console::draw()
	{
		int x = 5, y = 0;

//***bug fix
		if (!showing) return;

		//draw panel background
		panel->draw();

///***modification
		//draw text lines
		for (unsigned int n = 0; n < textlines.size(); n++)
		{
			font->setPosition(0, g_engine->getScreenHeight()/2);
			font->Print(x,(y*14)+  g_engine->getScreenHeight()/2, textlines[n], 0xFF000000);
			y += 1;

			if (y > 26) {
				if (x > 10) break;
				x = g_engine->getScreenWidth()/2 + 5;
				y = 0;
			}
		}
	}

	void Console::print(std::string text, int line)
	{
		if (line > -1) currentLine = line;
		textlines[currentLine] = text;
		if (currentLine++ > 52) currentLine = 0;
	}

	void Console::clear()
	{
		for (int n=0; n<55; n++)
			textlines.push_back("");
	}

};

