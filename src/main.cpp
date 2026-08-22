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

	// Variables for the game
	Vector2 position = { 200, 200 };
	int speed = 200;

	while (!WindowShouldClose()) {
		int fps = GetFPS();
		float dt = GetFrameTime();
		
		// Game logic
		if (IsKeyDown(KEY_RIGHT)) position.x += speed * dt;
		if (IsKeyDown(KEY_LEFT))  position.x -= speed * dt;
		if (IsKeyDown(KEY_DOWN))  position.y += speed * dt;
		if (IsKeyDown(KEY_UP))    position.y -= speed * dt;

		BeginTextureMode(canvas);
			ClearBackground(BLACK);
			DrawLine(0, 0, position.x, position.y, RED);
			DrawText(TextFormat("FPS: %i", fps), 0, 0, 30, RAYWHITE);
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
