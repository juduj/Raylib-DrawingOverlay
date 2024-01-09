#include <raylib.h>
#include <iostream>
#include "GetWindow.h"

int main()
{	
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	SetConfigFlags(FLAG_WINDOW_TRANSPARENT); // Configures window to be transparent
	InitWindow(screenWidth, screenHeight, "Transparent");
	SetWindowPosition(GetMonitorWidth(0) / 2 - screenWidth / 2, GetMonitorHeight(0) / 2 - screenHeight / 2);
	SetWindowState(FLAG_WINDOW_UNDECORATED); // Hide border/titlebar; omit if you want them there.
	RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);

	
	SetTargetFPS(60);

	std::string text = "ENEMY";

	Vector2 textSize = MeasureTextEx(GetFontDefault(), text.c_str(), 60, 1);
	Vector2 textPosition = {
	static_cast<float>(GetScreenWidth() / 2 - textSize.x / 2),
	static_cast<float>(GetScreenHeight() / 2 - textSize.y / 2)
	};

	GetWindowStuff();

	while(!WindowShouldClose())
	{
		BeginTextureMode(target);
		
		ClearBackground(BLANK);

		EndTextureMode();

		BeginDrawing();
		ClearBackground(BLANK);

		DrawTexturePro(target.texture, { 0.0f, 0.0f, 800.0f, 450.0f }, { 0.0f, 0.0f, 800.0f, 450.0f },
			{ 0.f, 0.f }, 0.0f, WHITE);

		//draw stuff here.
		DrawText(text.c_str(), textPosition.x, textPosition.y, 60, RED);

		EndDrawing();
	}

	UnloadRenderTexture(target);
	CloseWindow();
}     