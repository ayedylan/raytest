#include <raylib.h>

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Raylib Test");


  SetTargetFPS(60);
  
  Camera3D camera = { 0 };
  camera.position = (Vector3){ 5.0f, 1.5f, 0 }; // Camera position
  camera.target = (Vector3){ 0.0f, 1.0f, 0.0f };      // Camera looking at point
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;                                // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

  Vector3 p1Pos =  { 0.0f, 0.0f, 1.0f };

  Model p1 = LoadModel("assets/scene.gltf");
  
  
  while(!WindowShouldClose()) {

      
    ClearBackground(RAYWHITE);
    BeginDrawing();

    // Render the 3D ish 
    
    BeginMode3D(camera);

    DrawGrid(10, 1.0f);

    DrawModelEx(p1, p1Pos, (Vector3){ 1.0f, 0.0f, 0.0f }, 0.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, MAROON);

    
    EndMode3D();

    // Render the UI


    DrawFPS(10,10);
    
    EndDrawing();
    
  }
}
