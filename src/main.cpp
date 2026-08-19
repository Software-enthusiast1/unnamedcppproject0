#include "raylib.h"

int main() {
	// Screen Setup
	SetConfigFlags(FLAG_BORDERLESS_WINDOWED_MODE);
	InitWindow(0, 0, "My Game");
	int currentMonitor = GetCurrentMonitor();
	int refreshRate = GetMonitorRefreshRate(currentMonitor);
	SetTargetFPS(refreshRate);

	// Renders at standard 1080p, sizes up/down to screen
	const float FIXED_WIDTH = 1920;
	const float FIXED_HEIGHT = 1080;
	RenderTexture2D canvas = LoadRenderTexture((int)FIXED_WIDTH, (int)FIXED_HEIGHT);
	SetTextureFilter(canvas.texture, TEXTURE_FILTER_BILINEAR);

	while (!WindowShouldClose()) {
		BeginTextureMode(canvas);
			ClearBackground(BLACK);
			DrawLine(0, 0, 1920, 1080, RED);
			DrawLine(0, 1080, 1920, 0, RED);
			DrawLine(0, 0, 1920, 0, BLUE);
			DrawLine(0, 1080, 1920, 1080, BLUE);
			DrawLine(0, 0, 0, 1080, BLUE);
			DrawLine(1920, 0, 1920, 1080, BLUE);
			DrawText("Fixed Coordinate system", 50, 50, 30, RAYWHITE);
			DrawText("0,0", 0, 0, 30, RAYWHITE);
		EndTextureMode();

		BeginDrawing();
			ClearBackground(BLACK);
			Rectangle source = { 0.0f, 0.0f, FIXED_WIDTH, -FIXED_HEIGHT };
			Rectangle dest = { 0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight() };
			DrawTexturePro(canvas.texture, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE);
		EndDrawing();
	}

	UnloadRenderTexture(canvas);
	CloseWindow();
	return 0;
}
