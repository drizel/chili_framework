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
	void MoveCursor();
	void DrawCursor();
	void DrawBox(int x, int y, int r, int g, int b);
	void IsColliding(int x, int y, int a, int b);

	void CursorColor(bool collide);
	
private:
	MainWindow& wnd;
	Graphics gfx;
	
	int cursorX = 400;
	int cursorY = 300;

	int boxX = 200;
	int boxY = 200;

	int cursorVelocityX = 0;
	int cursorVelocityY = 0;
	int cursorMaxVelocity = 5;
	
	int cursorColorR = 255;
	int cursorColorG = 255;
	int cursorColorB = 255;

	bool isColliding = false;

	bool suppressUp = false;
	bool suppressDown = false;
	bool suppressLeft = false;
	bool suppressRight = false;
};