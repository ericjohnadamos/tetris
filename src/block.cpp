#include "block.h"

Block::Block()
	: m_cellSize(90),
	m_rotationState(0),
	m_rowOffset(0),
	m_colOffset(0),
	m_colors(GetCellColors()) {
}

void Block::Draw(int offsetX, int offsetY)
{
	std::vector<Position> tiles = GetCellPositions();
	for (Position tile : tiles) {
		DrawRectangle(
			tile.column * m_cellSize + offsetX,
			tile.row * m_cellSize + offsetY,
			m_cellSize - 1,
			m_cellSize - 1,
			m_colors[id]);
	}
}

void Block::Move(int r, int c) {
	m_rowOffset += r;
	m_colOffset += c;
}

void Block::Rotate() {
	++m_rotationState;
	if (m_rotationState == cells.size())
		m_rotationState = 0;
}

void Block::UndoRotate() {
	--m_rotationState;
	if (m_rotationState < 0)
		m_rotationState = 0;
}

std::vector<Position> Block::GetCellPositions() {
	std::vector<Position> tiles = cells[m_rotationState];
	std::vector<Position> newTiles;
	for (Position tile : tiles) {
		Position newPosition = Position(tile.row + m_rowOffset, tile.column + m_colOffset);
		newTiles.emplace_back(newPosition);
	}
	return newTiles;
}

