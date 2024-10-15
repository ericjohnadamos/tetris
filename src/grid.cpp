#include "grid.h"
#include "colors.h"
#include <algorithm>
#include <iostream>

Grid::Grid() {
	_numRows = 20;
	_numCols = 10;
	_cellSize = 90;
	Initialize();
	_colors = GetCellColors();
}

void Grid::Initialize() {
	std::fill(&grid[0][0], &grid[0][0] + _numRows * _numCols, 0);
}

void Grid::Print() const {
	for (int r = 0; r < _numRows; ++r) {
		for (int c = 0; c < _numCols; ++c)
			std::cout << grid[r][c] << " ";
		std::cout << "\n";
	}
}

void Grid::Draw() const {
	for (int r = 0; r < _numRows; ++r) {
		for (int c = 0; c < _numCols; ++c) {
			int cellValue = grid[r][c];
			DrawRectangle(c * _cellSize + 1, r * _cellSize + 1, _cellSize - 1, _cellSize - 1, _colors[cellValue]);
		}
	}
}

bool Grid::IsCellOutside(int r, int c) const
{
	if (r >= 0 && r < _numRows && c >= 0 && c < _numCols)
		return false;
	return true;
}

bool Grid::IsCellEmpty(int r, int c) const {
	return grid[r][c] == 0;
}

int Grid::ClearFullRows() {
	int completed = 0;
	for (int r = _numRows - 1; r >= 0; --r) {
		if (IsRowFull(r)) {
			ClearRow(r);
			++completed;
		}
		else if (completed > 0)
		{
			MoveRowDown(r, completed);
		}
	}
	return completed;
}

bool Grid::IsRowFull(int r) const {
	for (int c = 0; c < _numCols; ++c)
		if (grid[r][c] == 0)
			return false;
	return true;
}

void Grid::ClearRow(int r) {
	for (int c = 0; c < _numCols; ++c)
		grid[r][c] = 0;
}

void Grid::MoveRowDown(int r, int numRows) {
	for (int c = 0; c < _numCols; ++c) {
		grid[r + numRows][c] = grid[r][c];
		grid[r][c] = 0;
	}
}
