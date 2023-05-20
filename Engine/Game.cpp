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
}

void Game::MoveCursor()
{
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
	if (cursorX - 10 <= 1 || cursorX + 10 >= gfx.ScreenWidth) { cursorVelocityX *= -1; }
	if (cursorY - 10 <= 1 || cursorY + 10 >= gfx.ScreenHeight) { cursorVelocityY *= -1; }

	if (!wnd.kbd.KeyIsPressed(VK_UP)) { suppressUp = false; }
	if (!wnd.kbd.KeyIsPressed(VK_DOWN)) { suppressDown = false; }
	if (!wnd.kbd.KeyIsPressed(VK_LEFT)) { suppressLeft = false; }
	if (!wnd.kbd.KeyIsPressed(VK_RIGHT)) { suppressRight = false; }

	cursorX += cursorVelocityX;
	cursorY += cursorVelocityY;

	switchCursor = wnd.kbd.KeyIsPressed(VK_CONTROL);
	switchCursorColor = wnd.kbd.KeyIsPressed(VK_SHIFT);
	
}

void Game::DrawCursor()
{
	if (switchCursorColor)
	{
		cursorColorR = 255;
		cursorColorB = 0;
		cursorColorG = 0;
	}
	else
	{
		cursorColorR = 255;
		cursorColorB = 255;
		cursorColorG = 255;
	}

	if (switchCursor)
	{
		gfx.PutPixel(cursorX - 5, cursorY - 5, cursorColorR, cursorColorG, cursorColorB);
		gfx.PutPixel(cursorX - 4, cursorY - 5, cursorColorR, cursorColorG, cursorColorB);
		gfx.PutPixel(cursorX - 5, cursorY - 4, cursorColorR, cursorColorG, cursorColorB);
		gfx.PutPixel(cursorX + 5, cursorY + 5, cursorColorR, cursorColorG, cursorColorB);
		gfx.PutPixel(cursorX + 4, cursorY + 5, cursorColorR, cursorColorG, cursorColorB);
		gfx.PutPixel(cursorX + 5, cursorY + 4, cursorColorR, cursorColorG, cursorColorB);
		gfx.PutPixel(cursorX - 5, cursorY + 5, cursorColorR, cursorColorG, cursorColorB);
		gfx.PutPixel(cursorX - 5, cursorY + 4, cursorColorR, cursorColorG, cursorColorB);
		gfx.PutPixel(cursorX - 4, cursorY + 5, cursorColorR, cursorColorG, cursorColorB);
		gfx.PutPixel(cursorX + 5, cursorY - 5, cursorColorR, cursorColorG, cursorColorB);
		gfx.PutPixel(cursorX + 5, cursorY - 4, cursorColorR, cursorColorG, cursorColorB);
		gfx.PutPixel(cursorX + 4, cursorY - 5, cursorColorR, cursorColorG, cursorColorB);
	}

	else
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
}

void Game::ComposeFrame()
{
	DrawCursor();
}
