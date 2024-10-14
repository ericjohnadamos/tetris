#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	Grid grid;

private:
	std::vector<Block> _blocks;
	Block _currentBlock;
	Block _nextBlock;
};
