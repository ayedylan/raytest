#include <raylib.h>

int main(void) {
  const int screenWidth = 1000;
  const int screenHeight = 700;

  InitWindow(screenWidth, screenHeight, "Raylib Test");


  SetTargetFPS(60);
  
  Camera3D camera = { 0 };
  camera.position = (Vector3){ 10.0f, 10.0f, 0 }; // Camera position
  camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;                                // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

  // Load image into VRAM

  Image image = LoadImage("assets/heightmap.png");
  Mesh mesh = GenMeshHeightmap(image, (Vector3){ 16, 8, 16 }); // Generate heightmap mesh (RAM and VRAM)
  Model model = LoadModelFromMesh(mesh);
  
  
  Vector3 terrainPos =  { 0.0f, 0.0f, 0.0f };

  while(!WindowShouldClose()) {

      
    ClearBackground(RAYWHITE);
    BeginDrawing();

    // Render the 3D ish 
    
    BeginMode3D(camera);

    DrawModel(model, terrainPos, 1.0f, RED);
    DrawGrid(10, 1.0f);
    
    EndMode3D();

    // Render the UI


    DrawFPS(10,10);
    
    EndDrawing();
    
  }
}
