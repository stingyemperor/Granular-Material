#include "entities/ParticleGenerator.hpp"
#include "entities/ParticleUpdater.hpp"
#include "raylib.h"
#include "iostream"
#include "entities/ParticleSystem.hpp"
#include "utils/CompactNSearch.h"
#include "utils/PointSet.h"
#include <array>
#include <memory>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 1920;
  const int screenHeight = 1080;
  InitWindow(screenWidth, screenHeight, "Granular");
  // directory is relative to build folder
  Texture2D sphere = LoadTexture("../assets/sphere.png");
  Shader alpha = LoadShader(NULL,"../assets/depth.fs");
  // Define the camera to look into our 3d world
  Camera3D camera = { 0 };
  camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
  camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;                                // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type


  DisableCursor();                    // Limit cursor to relative movement inside the window

  SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------


  // ------------ Particle Stuff --------------------------------------
  
  ParticleSystem particle_system;
  BoxPosGen box_pos_gen;
  box_pos_gen.generate(&particle_system.particles);
  std::cout<< GetWorkingDirectory() << std::endl; 
  


  // ParticleSystem particleSystem(1000);
  //   ParticleEmitter particleEmitter;
  // EulerUpdater eulerUpdater;
  // FloorUpdater floorUpdater;
  // WindUpdater windUpdater;
  // CompactNSearch::NeighborhoodSearch nsearch(1.0f);
  // Constraints constraints;
  //
  // // make shared pointers for the generators
  // std::shared_ptr<BoxPosGen> boxGenPtr = std::make_shared<BoxPosGen>();
  // std::shared_ptr<BasicVelGen> basicVelGenPtr = std::make_shared<BasicVelGen>();
  // std::shared_ptr<ParticleEmitter> particleEmitterPtr= std::make_shared<ParticleEmitter>();
  // std::shared_ptr<EulerUpdater> eulerUpdaterPtr= std::make_shared<EulerUpdater>();
  // std::shared_ptr<FloorUpdater> floorUpdaterPtr= std::make_shared<FloorUpdater>();
  // std::shared_ptr<WindUpdater> windUpdaterPtr= std::make_shared<WindUpdater>();
  // std::shared_ptr<Constraints>constraintsPtr= std::make_shared<Constraints>();
  // // Decalre the generators
  // BoxPosGen boxGen;
  // BasicVelGen basicVelGen;
  // *boxGenPtr = boxGen;
  // *basicVelGenPtr = basicVelGen;
  // //Add generators to the emitter
  // particleEmitter.addGenerator(boxGenPtr);
  // // particleEmitter.addGenerator(basicVelGenPtr);
  // // add emitter to system
  // *particleEmitterPtr = particleEmitter;
  // particleSystem.addEmitter(particleEmitterPtr);
  // // add updater to system
  // *eulerUpdaterPtr = eulerUpdater;
  // *floorUpdaterPtr = floorUpdater;
  // particleSystem.addUpdater(eulerUpdaterPtr);
  // particleSystem.addUpdater(floorUpdaterPtr);
  // // particleSystem.addUpdater(windUpdaterPtr);
  // particleSystem.init();
  // // constraints.init(&particleSystem.m_particles);
  // constraints.setPointSet(nsearch,&particleSystem.m_particles);

  // ------------ Particle Stuff --------------------------------------
  // Main game loop
  while (!WindowShouldClose())        // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    UpdateCamera(&camera, CAMERA_FREE);

    if (IsKeyDown('Z')) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(DARKGRAY);

    BeginMode3D(camera);
    BeginShaderMode(alpha);
    
    particle_system.draw(camera,sphere);
    // particleSystem.update(GetFrameTime());
    // std::vector<unsigned int> n = constraints.getNeighbors(nsearch, &particleSystem.m_particles, 0);

    // for(unsigned int pid : n){
    //   glm::vec4 temp = particleSystem.m_particles.m_pos[pid];
    //   Vector3 pos = {temp.x, temp.y, temp.z};
    //   DrawSphereWires(pos, 0.3f, 6, 6, RED);
    // }
    // // particleSystem.update(0.01);
    // particleSystem.draw();
    DrawGrid(10, 1.0f);
    
    EndShaderMode();
    EndMode3D();

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();        // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
