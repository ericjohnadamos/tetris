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
	bool gameOver;

private:
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	std::vector<Block> _blocks;
	Block _currentBlock;
	Block _nextBlock;
};
