#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
	Game();
	void HandleInput();
	void Draw();
	void MoveBlockDown();
	Grid grid;
	bool gameOver;
	int score;

private:
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void MoveBlockLeft();
	void MoveBlockRight();
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
	std::vector<Block> _blocks;
	Block _currentBlock;
	Block _nextBlock;
};
