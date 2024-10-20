#include <iostream>
#include <raylib.h>
#include "game.h"

double lastUpdatedTime = 0;

static bool EventTriggered(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdatedTime >= interval) {
		lastUpdatedTime = currentTime;
		return true;
	}
	return false;
}

int main()
{
	const int screenWidth = 1500;
	const int screenHeight = 1800;

	Font font = LoadFontEx("Super Kloud.ttf", 64, 0, 0);

	InitWindow(screenWidth, screenHeight, "Tetris Game");
	SetTargetFPS(60);

	Game game = Game();

	while (!WindowShouldClose())
	{
		game.HandleInput();
		if (EventTriggered(0.2))
			game.MoveBlockDown();
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTextEx(font, "Score", { 365, 50 }, 380, 2, GREEN);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}