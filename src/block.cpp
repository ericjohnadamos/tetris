#include "block.h"

Block::Block() {
	_cellSize = 90;
	_rotationState = 0;
	colors = GetCellColors();
	_rowOffset = 0;
	_colOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
	std::vector<Position> tiles = GetCellPositions();
	for (Position tile : tiles) {
		DrawRectangle(
			tile.column * _cellSize + offsetX,
			tile.row * _cellSize + offsetY,
			_cellSize - 1,
			_cellSize - 1,
			colors[id]);
	}
}

void Block::Move(int r, int c) {
	_rowOffset += r;
	_colOffset += c;
}

void Block::Rotate() {
	++_rotationState;
	if (_rotationState == cells.size())
		_rotationState = 0;
}

void Block::UndoRotate() {
	--_rotationState;
	if (_rotationState < 0)
		_rotationState = 0;
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

