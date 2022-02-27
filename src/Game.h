//
// Created by JENNES Nathan on 27/02/2022.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <string>
#include "raylib-cpp.hpp"
#include "Cell.h"

class Game {

public:
	Game();
	Game(int _width, int _height, const char *title);

	void Start();

private:
	Cell cells[3][3];
	Cell::State playerState;

	bool won = false;
	bool draw = false;
	Cell winCellStart;
	Cell winCellEnd;

	int m_width, m_height;
	std::string title;
	raylib::Window window;


	void Update();
	void Render();
	void CheckForWinConditions();

};

#endif //TICTACTOE_GAME_H
