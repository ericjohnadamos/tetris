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
	bool IsCellOutside(int r, int c) const;
	bool IsCellEmpty(int r, int c) const;
	int ClearFullRows();
	int grid[20][10];

private:
	bool IsRowFull(int r) const;
	void ClearRow(int r);
	void MoveRowDown(int r, int numRows);
	int _numRows;
	int _numCols;
	int _cellSize;
	std::vector<Color> _colors;
};
