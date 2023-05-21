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
	MovePlayer();
	IsColliding();
	OutOfBounds();
}

void Game::ComposeFrame()
{
	DrawPlayer();

	DrawItem(item1X, item1Y, item1ColorR, item1ColorG, item1ColorB);
	DrawItem(item2X, item2Y, item2ColorR, item2ColorG, item2ColorB);
	DrawItem(item3X, item3Y, item3ColorR, item3ColorG, item3ColorB);
	DrawItem(item4X, item4Y, item4ColorR, item4ColorG, item4ColorB);
}

void Game::MovePlayer()
{
	if (wnd.kbd.KeyIsPressed(0x57))
	{
		playerY -= playerSpeed;
	}
	if (wnd.kbd.KeyIsPressed(0x53))
	{
		playerY += playerSpeed;
	}
	if (wnd.kbd.KeyIsPressed(0x41))
	{
		playerX -= playerSpeed;
	}
	if (wnd.kbd.KeyIsPressed(0x44))
	{
		playerX += playerSpeed;
	}

	if (outOfBounds)
	{
		playerX = 400;
		playerY = 300;
	}
}


void Game::DrawPlayer()
{
	gfx.PutPixel(playerX - 5, playerY, playerColorR, playerColorG, playerColorB);
	gfx.PutPixel(playerX - 4, playerY, playerColorR, playerColorG, playerColorB);
	gfx.PutPixel(playerX - 3, playerY, playerColorR, playerColorG, playerColorB);
	gfx.PutPixel(playerX + 5, playerY, playerColorR, playerColorG, playerColorB);
	gfx.PutPixel(playerX + 4, playerY, playerColorR, playerColorG, playerColorB);
	gfx.PutPixel(playerX + 3, playerY, playerColorR, playerColorG, playerColorB);
	gfx.PutPixel(playerX, playerY - 5, playerColorR, playerColorG, playerColorB);
	gfx.PutPixel(playerX, playerY - 4, playerColorR, playerColorG, playerColorB);
	gfx.PutPixel(playerX, playerY - 3, playerColorR, playerColorG, playerColorB);
	gfx.PutPixel(playerX, playerY + 5, playerColorR, playerColorG, playerColorB);
	gfx.PutPixel(playerX, playerY + 4, playerColorR, playerColorG, playerColorB);
	gfx.PutPixel(playerX, playerY + 3, playerColorR, playerColorG, playerColorB);
	
}

void Game::DrawItem(int x, int y, int r, int g, int b)
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

void Game::IsColliding()
{
	//penetrating
	if ((playerX + 3 > item1X - 3) && (playerX - 3 < item1X + 3)
		&& (playerY + 3 > item1Y - 3) && (playerY - 3 < item1Y + 3))
	{
		isColliding = true;
		item1ColorR = 0;
		item1ColorG = 0;
		item1ColorB = 0;
	}
	if ((playerX + 3 > item2X - 3) && (playerX - 3 < item2X + 3)
		&& (playerY + 3 > item2Y - 3) && (playerY - 3 < item2Y + 3))
	{
		isColliding = true;
		item2ColorR = 0;
		item2ColorG = 0;
		item2ColorB = 0;
	}
	if ((playerX + 3 > item3X - 3) && (playerX - 3 < item3X + 3)
		&& (playerY + 3 > item3Y - 3) && (playerY - 3 < item3Y + 3))
	{
		isColliding = true;
		item3ColorR = 0;
		item3ColorG = 0;
		item3ColorB = 0;
	}
	if ((playerX + 3 > item4X - 3) && (playerX - 3 < item4X + 3)
		&& (playerY + 3 > item4Y - 3) && (playerY - 3 < item4Y + 3))
	{
		isColliding = true;
		item4ColorR = 0;
		item4ColorG = 0;
		item4ColorB = 0;
	}
	else
	{ 
		isColliding = false;		
	}	
}

void Game::OutOfBounds()
{
	if (playerX - 6 <= 5) { outOfBounds = true; }
	else if (playerY - 6 <= 5) { outOfBounds = true; }
	else if (playerX + 6 >= 795) { outOfBounds = true; }
	else if (playerY + 5 >= 595) { outOfBounds = true; }
	else { outOfBounds = false; }
}

