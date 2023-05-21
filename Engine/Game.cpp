/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	MoveCursor();
	IsColliding(cursorX, cursorY, boxX, boxY);
	CursorColor(isColliding);
}

void Game::ComposeFrame()
{
	DrawCursor();
	DrawBox(boxX,boxY,255,255,255);
}

void Game::MoveCursor()
{
	//Give cursor velocity
	if (wnd.kbd.KeyIsPressed(VK_UP) && cursorVelocityY > -cursorMaxVelocity && suppressUp == false)
	{
		cursorVelocityY -= 1;	
		suppressUp = true;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN) && cursorVelocityY < cursorMaxVelocity && suppressDown == false)
	{
		cursorVelocityY += 1;
		suppressDown = true;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT) && cursorVelocityX > -cursorMaxVelocity && suppressLeft == false)
	{
		cursorVelocityX -= 1;
		suppressLeft = true;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT) && cursorVelocityX < cursorMaxVelocity && suppressRight == false)
	{
		cursorVelocityX += 1;
		suppressRight = true; 
	}

	//Bounce off screen edge
	if (cursorX - 10 <= 1 || cursorX + 10 >= gfx.ScreenWidth) { cursorVelocityX *= -1; }
	if (cursorY - 10 <= 1 || cursorY + 10 >= gfx.ScreenHeight) { cursorVelocityY *= -1; }

	//Suppress key input
	if (!wnd.kbd.KeyIsPressed(VK_UP)) { suppressUp = false; }
	if (!wnd.kbd.KeyIsPressed(VK_DOWN)) { suppressDown = false; }
	if (!wnd.kbd.KeyIsPressed(VK_LEFT)) { suppressLeft = false; }
	if (!wnd.kbd.KeyIsPressed(VK_RIGHT)) { suppressRight = false; }

	//Move the cursor
	cursorX += cursorVelocityX;
	cursorY += cursorVelocityY;
}

void Game::DrawCursor()
{
	gfx.PutPixel(cursorX - 5, cursorY, cursorColorR, cursorColorG, cursorColorB);
	gfx.PutPixel(cursorX - 4, cursorY, cursorColorR, cursorColorG, cursorColorB);
	gfx.PutPixel(cursorX - 3, cursorY, cursorColorR, cursorColorG, cursorColorB);
	gfx.PutPixel(cursorX + 5, cursorY, cursorColorR, cursorColorG, cursorColorB);
	gfx.PutPixel(cursorX + 4, cursorY, cursorColorR, cursorColorG, cursorColorB);
	gfx.PutPixel(cursorX + 3, cursorY, cursorColorR, cursorColorG, cursorColorB);
	gfx.PutPixel(cursorX, cursorY - 5, cursorColorR, cursorColorG, cursorColorB);
	gfx.PutPixel(cursorX, cursorY - 4, cursorColorR, cursorColorG, cursorColorB);
	gfx.PutPixel(cursorX, cursorY - 3, cursorColorR, cursorColorG, cursorColorB);
	gfx.PutPixel(cursorX, cursorY + 5, cursorColorR, cursorColorG, cursorColorB);
	gfx.PutPixel(cursorX, cursorY + 4, cursorColorR, cursorColorG, cursorColorB);
	gfx.PutPixel(cursorX, cursorY + 3, cursorColorR, cursorColorG, cursorColorB);
	
}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x - 5, y - 5, r, g, b);
	gfx.PutPixel(x - 4, y - 5, r, g, b);
	gfx.PutPixel(x - 5, y - 4, r, g, b);
	gfx.PutPixel(x + 5, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y + 4, r, g, b);
	gfx.PutPixel(x - 5, y + 5, r, g, b);
	gfx.PutPixel(x - 5, y + 4, r, g, b);
	gfx.PutPixel(x - 4, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y - 5, r, g, b);
	gfx.PutPixel(x + 5, y - 4, r, g, b);
	gfx.PutPixel(x + 4, y - 5, r, g, b);
}

void Game::IsColliding(int x, int y, int a, int b)
{
	if ((x + 5 > a - 5) && (x - 5 < a + 5)
		&& (y + 5 > b - 5) && (y - 5 < b + 5))
	{
		isColliding = true;
	}
	else
	{ 
		isColliding = false;
	}
}

void Game::CursorColor(bool collide)
{
	if (!collide)
	{
	cursorColorR = 255;
	cursorColorB = 255;
	cursorColorG = 255;
	}
	if (collide)
	{
	cursorColorR = 255;
	cursorColorB = 0;
	cursorColorG = 0;
	}
}

