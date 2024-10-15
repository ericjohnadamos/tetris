#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void HandleInput();
	void Draw();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	Grid grid;

private:
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	std::vector<Block> _blocks;
	Block _currentBlock;
	Block _nextBlock;
};
