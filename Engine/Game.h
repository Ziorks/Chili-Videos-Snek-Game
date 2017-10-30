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
#include "Snake.h"
#include "Board.h"
#include "Goal.h"
#include <random>

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
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Board brd;
	Snake snek;
	Location delta_loc = {1,0};
	std::mt19937 rng;
	Goal goal;
	Color boardColor = Colors::White;
	int snekMoveCounter = 0;
	int snekSpeedUpCounter = 0;
	int snekMovePeriod = 15;                         //starting speed
	static constexpr int snekDeltaPeriod = 1;        //how much to speed up by when enough are eaten
	static constexpr int snekMaxPeriod = 3;          //lower number = faster max speed
	static constexpr int EatThisManyToSpeedUp = 2;   //what it says
	bool gameIsStarted = false;
	bool gameIsOver = false;
	int directionCheck = 0;                          //0=right, 1=left, 2=up, 3=down
	/********************************/
};