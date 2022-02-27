//
// Created by JENNES Nathan on 27/02/2022.
//

#include <iostream>
#include "Cell.h"

Cell::Cell()
	: Cell(0, 0, 0, 0)
{
}

Cell::Cell(float _x, float _y, float _width, float _height)
	: state(Empty), position(_x, _y),
	  size(_width, _height), cellBoundingBox(_x, _y, _width, _height)
{
}

void Cell::Render()
{
	DrawRectangleLinesEx(cellBoundingBox, 3, GRAY);

	if (state == Cross)
	{
		DrawLineEx({position.x + (size.x / 5), position.y + (size.y / 5)},
				   {position.x + (size.x - size.x / 5), position.y + (size.y - size.y / 5)},
				   3, BLUE);
		DrawLineEx({position.x + (size.x / 5), position.y + (size.y - size.y / 5)},
					{position.x + (size.x - size.x / 5), position.y + (size.y / 5)},
				 3, BLUE);
	}
	else if (state == Circle)
	{
		DrawCircle(position.x + (size.x / 2), position.y + (size.y / 2),
				   std::min(size.x / 4, size.y / 4), RED);
		DrawCircle(position.x + (size.x / 2), position.y + (size.y / 2),
				   std::min(size.x * 0.22, size.y * 0.22), WHITE);
	}
}
