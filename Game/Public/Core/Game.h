#pragma once

#include "Core/IGame.h"

// Example game implementation
class MyVoxelGame : public IGame {
public:
    MyVoxelGame();
    ~MyVoxelGame() override;
    
    void Initialize() override;
    void Update(float deltaTime) override;
    void Render() override;
    void Shutdown() override;
};