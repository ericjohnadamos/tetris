#include "game.h"
#include <random>

Game::Game() {
	grid = Grid();
	_blocks = GetAllBlocks();
	_currentBlock = GetRandomBlock();
	_nextBlock = GetRandomBlock();
	gameOver = false;
}

Block Game::GetRandomBlock() {
	if (_blocks.empty())
		_blocks = GetAllBlocks();

	int randIndex = rand() % _blocks.size();
	Block block = _blocks[randIndex];
	_blocks.erase(_blocks.begin() + randIndex);
	return block;
}

std::vector<Block> Game::GetAllBlocks() {
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::HandleInput() {
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0) {
		gameOver = false;
		Reset();
	}
	switch (keyPressed)
	{
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		break;
	case KEY_SPACE:
		RotateBlock();
		break;
	}
}

void Game::Draw() {
	grid.Draw();
	_currentBlock.Draw();
}

void Game::MoveBlockLeft() {
	if (gameOver)
		return;
	_currentBlock.Move(0, -1);
	if (IsBlockOutside() || !BlockFits())
		_currentBlock.Move(0, 1);
}

void Game::MoveBlockRight() {
	if (gameOver)
		return;
	_currentBlock.Move(0, 1);
	if (IsBlockOutside() || !BlockFits())
		_currentBlock.Move(0, -1);
}

void Game::MoveBlockDown() {
	if (gameOver)
		return;
	_currentBlock.Move(1, 0);
	if (IsBlockOutside() || !BlockFits()) {
		_currentBlock.Move(-1, 0);
		LockBlock();
	}
}

void Game::RotateBlock() {
	if (gameOver)
		return;
	_currentBlock.Rotate();
	if (IsBlockOutside() || !BlockFits())
		_currentBlock.UndoRotate();
}

bool Game::IsBlockOutside() {
	std::vector<Position> tiles = _currentBlock.GetCellPositions();
	for (Position tile : tiles)
		if (grid.IsCellOutside(tile.row, tile.column))
			return true;
	return false;
}

void Game::LockBlock() {
	std::vector<Position> tiles = _currentBlock.GetCellPositions();
	for (Position tile : tiles)
		grid.grid[tile.row][tile.column] = _currentBlock.id;
	_currentBlock = _nextBlock;

	if (!BlockFits()) {
		gameOver = true;
	}

	_nextBlock = GetRandomBlock();
	grid.ClearFullRows();
}

bool Game::BlockFits() {
	std::vector<Position> tiles = _currentBlock.GetCellPositions();
	for (Position tile : tiles)
		if (!grid.IsCellEmpty(tile.row, tile.column))
			return false;
	return true;
}

void Game::Reset() {
	grid.Initialize();
	_blocks = GetAllBlocks();
	_currentBlock = GetRandomBlock();
	_nextBlock = GetRandomBlock();
}

