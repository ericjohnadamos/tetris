#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
	Grid();
	void Initialize();
	void Print() const;
	void Draw() const;
	int grid[20][10];

private:
	int _numRows;
	int _numCols;
	int _cellSize;
	std::vector<Color> _colors;
};
