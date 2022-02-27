//
// Created by JENNES Nathan on 27/02/2022.
//

#ifndef TICTACTOE_CELL_H
#define TICTACTOE_CELL_H

#include "raylib-cpp.hpp"

class Cell {

public:
	enum State
	{
		Empty, Cross, Circle
	};

	State state;
	raylib::Vector2 position;
	raylib::Vector2 size;

	Cell();
	Cell(float x, float y, float width, float height);

	void Render();

private:
	raylib::Rectangle cellBoundingBox;

};

#endif //TICTACTOE_CELL_H
