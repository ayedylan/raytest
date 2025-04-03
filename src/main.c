#include <raylib.h>

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Raylib Test");

  Camera3D camera = { 0 };
  camera.position = (Vector3){ 10.0f, 1.0f, 0 }; // Camera position
  camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;                                // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

  while(!WindowShouldClose()) {

    
    ClearBackground(RAYWHITE);
    BeginDrawing();

    BeginMode3D(camera);

    DrawGrid(10, 1.0f);

    EndMode3D();

    EndDrawing();
    
  }
}
