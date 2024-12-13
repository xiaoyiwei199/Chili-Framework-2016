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
	box = Box();
	box.SetX(400);
	box.SetY(300);
	box.SetWidth(50);
	box.SetHeight(50);
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
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) 
	{
		if (box.x - 1 < 0) 
		{
			box.SetX(0);
		}
		else
		{
			box.SetX(box.x - 1);
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) 
	{
		if (box.x + box.width+ 1 > Graphics::ScreenWidth) 
		{
			box.SetX(Graphics::ScreenWidth-box.width);
		}
		else 
		{
			box.SetX(box.x + 1);
		}
		
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) 
	{
		if (box.y - 1 < 0) 
		{
			box.SetY(0);
		}
		else
		{
			box.SetY(box.y - 1);
		}
		
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) 
	{
		if (box.y + box.height + 1 > Graphics::ScreenHeight) 
		{
			box.SetY(Graphics::ScreenHeight - box.height);
		}
		else 
		{
			box.SetY(box.y + 1);
		}
	}

	UpdateSize();
}
/// <summary>
/// 根据box的位置和边画出box
/// </summary>
void Game::DrawBox()
{
	for (int i = box.x; i < box.width+box.x; i++) 
	{
		for(int j=box.y;j<box.height+box.y;j++)
		{
			gfx.PutPixel(i, j, 255, 255, 255);
		}
	}
}

void Game::ComposeFrame()
{
	DrawBox();
}
/// <summary>
/// 控制box的大小
/// </summary>
void Game::UpdateSize() 
{
	if (wnd.kbd.KeyIsPressed('A')) 
	{
		
	}
	if (wnd.kbd.KeyIsPressed('D')) 
	{
		box.width += 1;
	}
	if (wnd.kbd.KeyIsPressed('W'))
	{

	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		box.height += 1;
	}
}

