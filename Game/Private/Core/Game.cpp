#include "Core/Game.h"

#include "Core/EngineInfo.h"
#include "Core/GameInfo.h"
#include "Core/VoxCore.h"

MyVoxelGame::MyVoxelGame() {
    LOG_INFO("Game", "Creating MyVoxelGame instance");
}

MyVoxelGame::~MyVoxelGame() {
    LOG_INFO("Game", "Destroying MyVoxelGame instance");
}

void MyVoxelGame::Initialize() {

    LOG_INFO("Game", "Initializing MyVoxelGame - Version: {}", MyVoxelGameInfo::GetGameVersion());
}

void MyVoxelGame::Update(float deltaTime) {
    static int frameCount = 0;
    frameCount++;
    if (frameCount % 60 == 0) {
        LOG_ONCE(Info, "Game", "Game running... Frame: {}", frameCount);
    }
}

void MyVoxelGame::Render() {
    // Simple render logic
    LOG_ONCE(Info, "Render", "Rendering game frame");
}

void MyVoxelGame::Shutdown() {
    LOG_INFO("Game", "Shutting down game...");
}

