#include <iostream>
#include <raylib.h>
#include "game.h"

int main()
{
	const int screenWidth = 900;
	const int screenHeight = 1800;

	InitWindow(screenWidth, screenHeight, "Tetris Game");
	SetTargetFPS(60);

	Game game = Game();

	while (!WindowShouldClose())
	{
		game.HandleInput();
		BeginDrawing();
		ClearBackground(BLACK);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}