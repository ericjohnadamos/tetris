#include <iostream>
#include <raylib.h>
#include "game.h"
#include "colors.h"

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
	const int xMargin = 100;

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

		// Todo: Fix the calculations when you have time
		const float scoreTextWidth = MeasureText("SCORE", 128);
		DrawTextEx(font, "SCORE", { 900 + (scoreTextWidth / 4), 100 }, 128, 2, GREEN);
		const Rectangle scoreRect = { 900 + xMargin, 256, 600 - (xMargin * 2), 128 };
		DrawRectangleRounded(scoreRect, 0.3, 6, lightBlue);

		const float nextTextWidth = MeasureText("NEXT", 128);
		DrawTextEx(font, "NEXT", { 900 + (nextTextWidth / 3), 384 + xMargin}, 128, 2, GREEN);
		const Rectangle nextRect = { scoreRect.x, scoreRect.y + 380, scoreRect.width, scoreRect.height + 128 };
		DrawRectangleRounded(nextRect, 0.3, 6, lightBlue);

		if (game.gameOver)
			DrawTextEx(font, "GAME OVER", { nextRect.x, scoreRect.y + scoreRect.height + 720 }, 64, 2, GREEN);

		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}