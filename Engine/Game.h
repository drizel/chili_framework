/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void MovePlayer();
	void DrawPlayer();
	void DrawItem(int x, int y, int r, int g, int b);
	void IsColliding();
	void OutOfBounds();
	
private:
	MainWindow& wnd;
	Graphics gfx;
	
	int playerX = gfx.ScreenWidth / 2;
	int playerY = gfx.ScreenHeight / 2;

	int item1X = 200;
	int item1Y = 200;

	int item2X = 200;
	int item2Y = 400;

	int item3X = 600;
	int item3Y = 200;

	int item4X = 600;
	int item4Y = 400;


	int playerSpeed = 3;
	
	int playerColorR = 255;
	int playerColorG = 255;
	int playerColorB = 255;

	int item1ColorG = 255;
	int item1ColorB = 255;
	int item1ColorR = 255;

	int item2ColorR = 255;
	int item2ColorG = 255;
	int item2ColorB = 255;

	int item3ColorR = 255;
	int item3ColorG = 255;
	int item3ColorB = 255;

	int item4ColorR = 255;
	int item4ColorG = 255;
	int item4ColorB = 255;

	bool isColliding = false;
	bool outOfBounds = false;
};