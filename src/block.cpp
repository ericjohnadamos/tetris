#include "block.h"

Block::Block() {
	_cellSize = 90;
	_rotationState = 0;
	colors = GetCellColors();
	_rowOffset = 0;
	_colOffset = 0;
}

void Block::Draw()
{
	std::vector<Position> tiles = GetCellPositions();
	for (Position tile : tiles) {
		DrawRectangle(
			tile.column * _cellSize + 1,
			tile.row * _cellSize + 1,
			_cellSize - 1,
			_cellSize - 1,
			colors[id]);
	}
}

void Block::Move(int r, int c) {
	_rowOffset += r;
	_colOffset += c;
}

std::vector<Position> Block::GetCellPositions() {
	std::vector<Position> tiles = cells[_rotationState];
	std::vector<Position> newTiles;
	for (Position tile : tiles) {
		Position newPosition = Position(tile.row + _rowOffset, tile.column + _colOffset);
		newTiles.emplace_back(newPosition);
	}
	return newTiles;
}

