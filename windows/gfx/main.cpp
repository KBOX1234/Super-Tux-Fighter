#define OLC_PGE_APPLICATION
#include "E.h"
#include <fstream>
#include <stdlib.h>
#include <filesystem>
#include <unistd.h>

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Example";
	}

public:
long sx = 0;
long sy = 0;

std::string b;

	bool gridbox(int mapX, int mapY){
		const char boxWidth = 64;
		while(mapX > 0){
			olc::DrawRect(mapX*64, mapY*64, olc::RED);
			mapX--;
		}
	}
    bool button(int x, int y, int scaleX, int scaleY, std::string text, unsigned char R, unsigned char G, unsigned char B, unsigned char R2, unsigned char G2, unsigned char B2, unsigned char R3, unsigned char G3, unsigned char B3, unsigned char Tscale){
		y = y + sy;
		x = x + sx;
		int x2 = x;
		int y2 = y;
		FillRect(x + 2, y + 2, scaleX - 2, scaleY - 2, olc::Pixel(0, 0, 0));
		DrawRect(x, y, scaleX, scaleY, olc::Pixel(R, G, B));
		FillRect(x + 1, y + 1, scaleX - 2, scaleY - 2, olc::Pixel(R2, G2, B2));
		DrawString(x + 4, y + 4, text, olc::Pixel(R3, G3, B3), Tscale);
		float mx = float(GetMouseX());
		float my = float(GetMouseY());
		if (GetMouse(0).bHeld && mx < x + scaleX && mx > x && my < y + scaleY && my > y){
			FillRect(x + 2, y + 2, scaleX - 2, scaleY - 2, olc::Pixel(R3 - 50, G3 - 50, B3 - 50));
			DrawRect(x + 1, y + 1, scaleX - 1, scaleY - 1, olc::Pixel(0, 0, 0));
			DrawString(x + 8, y + 8, text, olc::Pixel(R3, G3, B3), Tscale);
			return true;
		}
		else{
			return false;
		}
	}
	bool Sbutton(int x, int y, int scaleX, int scaleY, std::string spr, unsigned char R, unsigned char G, unsigned char B, unsigned char R2, unsigned char G2, unsigned char B2, unsigned char R3, unsigned char G3, unsigned char B3, unsigned char Sscale){
		y = y + sy;
		x = x + sx;
		int x2 = x;
		int y2 = y;
		FillRect(x + 2, y + 2, scaleX - 2, scaleY - 2, olc::Pixel(0, 0, 0));
		DrawRect(x, y, scaleX, scaleY, olc::Pixel(R, G, B));
		FillRect(x + 1, y + 1, scaleX - 2, scaleY - 2, olc::Pixel(R2, G2, B2));
		olc::Sprite *bt;
		bt = new olc::Sprite(""+spr);
		DrawSprite(x, y, bt, Sscale);
		float mx = float(GetMouseX());
		float my = float(GetMouseY());
		if (GetMouse(0).bHeld && mx < x + scaleX && mx > x && my < y + scaleY && my > y){
			FillRect(x + 2, y + 2, scaleX - 2, scaleY - 2, olc::Pixel(R3 - 50, G3 - 50, B3 - 50));
			DrawRect(x + 1, y + 1, scaleX - 1, scaleY - 1, olc::Pixel(0, 0, 0));
			DrawSprite(x + 2, y + 2, bt, Sscale);
			return true;
		}
		else{
			return false;
		}
	}
	bool cheakBox(int x, int y, short scale, unsigned char R, unsigned char G, unsigned char B, unsigned char R2, unsigned char G2, unsigned char B2){
		int x2 = x;
		int y2 = y;
		DrawRect(x, y, scale, scale, olc::Pixel(R, G, B));
		FillRect(x + 2, y + 2, scale - 2, scale - 2, olc::Pixel(200, 200, 200));
		bool state = false;
		float mx = float(GetMouseX());
		float my = float(GetMouseY());
		if (GetMouse(0).bHeld && mx < x + scale && mx > x && my < y + scale && my > y && state == false){
			//FillRect(x + 4, y + 4, scale - 4, scale - 4, olc::Pixel(0, 0, 180));
			state = true;
		}
		else if (GetMouse(0).bHeld && mx < x + scale && mx > x && my < y + scale && my > y && state == true){
			state = false;
			//DrawRect(x + 2, y + 2, scale - 2, scale - 2, olc::Pixel(0, 0, 0));
			//FillRect(x + 2, y + 2, scale - 2, scale - 2, olc::Pixel(0, 0, 0));
		}
		if(state == true){
			FillRect(x + 4, y + 4, scale - 4, scale - 4, olc::Pixel(0, 0, 180));
			state = true;
		}
		else{
			FillRect(x + 2, y + 2, scale - 2, scale - 2, olc::Pixel(200, 200, 200));
		}
		return state;
	}
	bool pannel(int x, int y, int scaleX, int scaleY, unsigned char R, unsigned char G, unsigned char B, bool fill, short bwidth, unsigned char R2, unsigned char G2, unsigned char B2){
		int bwidth2 =  bwidth;
		int x2 = x;
		int y2 = y;
		int scaleX2 = scaleX;
		int scaleY2 = scaleY;
		while(bwidth2 > 0){
			DrawRect(x2, y2, scaleX2, scaleY2, olc::Pixel(R, G, B));
			x2 = x2 + 1;
			y2 = y2 + 1;
			scaleX2 = scaleX2 - 1;
			scaleY2 = scaleY2 - 1;
			bwidth2 = bwidth2 - 2; 
		}
		if(fill == true){
			FillRect(x + 1, y + 1, scaleX - 1, scaleY - 1, olc::Pixel(R2, G2, B2));
		}
		return true;
	}
	unsigned int tileINC = 0;
	int tileX[16388];
	int tileY[16388];


	bool OnUserCreate() override{
		
		return true;
	}
	olc::Sprite *w = new olc::Sprite("WARNING.png");
	olc::Sprite *g = new olc::Sprite("grass.png");
	olc::Sprite *s = new olc::Sprite("stone.png");
	bool grasshold = false;
	bool stonehold = false;
	
	bool OnUserUpdate(float fElapsedTime) override{
		//DrawSprite(0, 0, w, 1);
		Clear(olc::WHITE);
		bool save = button(20, 20, 70, 30, "save", 0xf0, 0xf0, 0xf0, 0xfa, 0xfa, 0xfa, 0x0, 0x0, 0x0, 2);
		bool open = button(20 + 70 +10, 20, 70, 30, "open", 0xf0, 0xf0, 0xf0, 0xfa, 0xfa, 0xfa, 0, 0, 0, 2);
		bool grass = Sbutton(20 + 70 + 10 + 70 + 10, 20, 64, 64, "grass.png", 0xf0, 0xf0, 0xf0, 0xfa, 0xfa, 0xfa, 0, 0, 0, 1);
		bool stone = Sbutton(20 + 70 + 10 + 70 + 10 + 70 + 10, 20, 64, 64, "stone.png", 0xf0, 0xf0, 0xf0, 0xfa, 0xfa, 0xfa, 0, 0, 0, 1);
		if(GetKey(olc::Key::UP).bPressed) sy = sy + 32;
		if(GetKey(olc::Key::DOWN).bPressed) sy = sy - 32;
		if(GetKey(olc::Key::LEFT).bPressed) sx = sx + 32;
		if(GetKey(olc::Key::RIGHT).bPressed) sx = sx - 32;
		if(grass == true) grasshold = true;
		if(stone == true) stonehold = true;
		
		
		return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(1280, 720, 1, 1))
		demo.Start();
	return 0;
}