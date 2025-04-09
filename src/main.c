#include "raylib.h"

int main(void)
{
    	const int screenWidth = 1200;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "raylib test");
	ToggleFullscreen();

	Camera3D camera = { 0 };
	camera.position = (Vector3){ 10.0f, 1.0f, 0.0f };
	camera.target = (Vector3)  { 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3) { 0.0f, 1.0f, 0.0f };
	camera.fovy = 10.0;
	camera.projection = CAMERA_ORTHOGRAPHIC;

	SetTargetFPS(60);

	Vector3 p1Pos = {0.0f, 0.0f, 0.0f };

	Image image = LoadImage("assets/heightmap.png");     // Load heightmap image (RAM
								    //
	Texture2D texture = LoadTextureFromImage(image);        // Convert image to texture (VRAM)

	Mesh mesh = GenMeshHeightmap(image, (Vector3){ 160, 8, 160 }); // Generate heightmap mesh (RAM and VRAM)
	Model model = LoadModelFromMesh(mesh);                  // Load model from generated mesh

	model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture; // Set map diffuse texture
	Vector3 mapPosition = { -80.0f, -1.0f, -80.0f };           // Define model position

	UnloadImage(image);
	while (!WindowShouldClose()) {
		ClearBackground(RAYWHITE);

		if (IsKeyDown (KEY_A)) {
			p1Pos.z += 0.1f;
		} else if (IsKeyDown (KEY_D)) {
			p1Pos.z -= 0.1f;
		} else if (IsKeyDown (KEY_S)) {
			p1Pos.x += 0.1f;
			camera.position.z += 0.1f;
		} else if (IsKeyDown (KEY_W)) {
			p1Pos.x -= 0.1f;
		};


		camera.target = p1Pos;
		camera.position.x = p1Pos.x + 10.0f;
		camera.position.z = p1Pos.z;
		camera.position.y = GetMouseY()/20.0+10.0;

		BeginDrawing();
	    
		BeginMode3D(camera);

		DrawCube(p1Pos, 1.0f, 1.0f, 1.0f, RED);

		DrawCube( (Vector3){ 5, 0, 5 }, 1.0f, 1.0f, 1.0f, BLUE);

		DrawModel(model, mapPosition, 1.0f, RED);

		EndMode3D();

		DrawFPS(10, 10);

		EndDrawing();

	}

	CloseWindow();

	return 0;
}
