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

void Game::Draw() {
	grid.Draw();
	_currentBlock.Draw();
}

