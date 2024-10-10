#include <iostream>
#include <raylib.h>

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Tetris Game");

	// Set the game to run at 60 fps
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}