#include "game.h"
#include <random>

Game::Game() {
	grid = Grid();
	_blocks = GetAllBlocks();
	_currentBlock = GetRandomBlock();
	_nextBlock = GetRandomBlock();
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
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::HandleInput() {
	int keyPressed = GetKeyPressed();
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
	}
}

void Game::Draw() {
	grid.Draw();
	_currentBlock.Draw();
}

void Game::MoveBlockLeft() {
	_currentBlock.Move(0, -1);
}

void Game::MoveBlockRight() {
	_currentBlock.Move(0, 1);
}

void Game::MoveBlockDown() {
	_currentBlock.Move(1, 0);
}
