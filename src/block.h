#pragma once

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
public:
	int id;
	Block();
	void Draw(int offsetX, int offsetY);
	void Move(int r, int c);
	void Rotate();
	void UndoRotate();
	std::vector<Position> GetCellPositions();
	std::map<int, std::vector<Position>> cells;

private:
	int m_cellSize;
	int m_rotationState;
	int m_rowOffset;
	int m_colOffset;
	std::vector<Color> m_colors;
};
