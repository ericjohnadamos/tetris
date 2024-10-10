#include <iostream>
#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main()
{
	const int screenWidth = 900;
	const int screenHeight = 1800;

	InitWindow(screenWidth, screenHeight, "Tetris Game");

	// Set the game to run at 60 fps
	SetTargetFPS(60);

	Grid grid = Grid();

	TBlock block = TBlock();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		grid.Draw();
		block.Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}