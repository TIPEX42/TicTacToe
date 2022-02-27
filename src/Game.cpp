//
// Created by JENNES Nathan on 27/02/2022.
//

#include "Game.h"
#include <iostream>

Game::Game()
	:Game(300, 300, "Game")
{

}

Game::Game(int _width, int _height, const char *_title)
	:playerState(Cell::Cross), title(_title), window(_width, _height, _title)
{
	m_width = _width;
	m_height = _height;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cells[i][j] = Cell(j * (m_width / 3), i * (m_height / 3),
							   	m_width / 3, m_height / 3);
		}
	}

	SetTargetFPS(60);
}

void Game::Update()
{
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		int posX = GetMouseX();
		int posY = GetMouseY();

		if (posX < 0 || posX >= m_width || posY < 0 || posY >= m_height)
			return ;


		posX = posX / (m_width / 3);
		posY = posY / (m_height / 3);

		if (cells[posY][posX].state == Cell::Empty)
		{
			cells[posY][posX].state = playerState;
			CheckForWinConditions();

			if (won)
				return ;
			if (playerState == Cell::Circle)
				playerState = Cell::Cross;
			else
				playerState = Cell::Circle;

		}
	}
}

void Game::CheckForWinConditions()
{
	for (Cell* row : cells)
	{
		if (row[0].state != Cell::Empty && row[0].state == row[1].state && row[1].state == row[2].state)
		{
			won = true;
			winCellStart = row[0];
			winCellEnd = row[2];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (cells[0][i].state != Cell::Empty && cells[0][i].state == cells[1][i].state &&
			cells[1][i].state == cells[2][i].state)
		{
			won = true;
			winCellStart = cells[0][i];
			winCellEnd = cells[2][i];
		}
	}

	if (cells[0][0].state != Cell::Empty && cells[0][0].state == cells[1][1].state &&
		cells[1][1].state == cells[2][2].state)
	{
		won = true;
		winCellStart = cells[0][0];
		winCellEnd = cells[2][2];
	}

	if (cells[2][0].state != Cell::Empty && cells[2][0].state == cells[1][1].state &&
		cells[1][1].state == cells[0][2].state)
	{
		won = true;
		winCellStart = cells[2][0];
		winCellEnd = cells[0][2];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cells[i][j].state == Cell::Empty)
				return ;
		}
	}

	draw = true;
}

void Game::Render()
{
	BeginDrawing();
	window.ClearBackground(WHITE);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cells[i][j].Render();
		}
	}

	if (won)
	{
		DrawLineEx(winCellStart.position + winCellStart.size / 2,
				   winCellEnd.position + winCellEnd.size / 2, 3, MAROON);

		if (playerState == Cell::Cross)
		{
			DrawText("Cross won !", m_width / 2 - MeasureText("Cross won !", 40) / 2,
					 m_height / 2, 40, BLACK);
		}
		else {
			DrawText("Circle won !", m_width / 2 - MeasureText("Circle won !", 40) / 2,
					 m_height / 2, 40, BLACK);
		}
	}

	if (draw)
	{
		DrawText("Draw !", m_width / 2 - MeasureText("Draw !", 40) / 2,
				 m_height / 2, 40, BLACK);
	}
	EndDrawing();
}

void Game::Start()
{
	while (!window.ShouldClose())
	{
		if (!won && !draw)
			Update();
		Render();
	}
}
