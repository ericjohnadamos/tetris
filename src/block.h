#pragma once

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
public:
	Block();
	void Draw();
	void Move(int r, int c);
	void Rotate();
	void UndoRotate();
	std::vector<Position> GetCellPositions();
	int id;
	std::map<int, std::vector<Position>> cells;

private:
	int _cellSize;
	int _rotationState;
	std::vector<Color> colors;
	int _rowOffset;
	int _colOffset;
};
