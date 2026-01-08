//
// Created by IDKTHIS on 06.01.2026.
//

#include "Core/VoxCore.h"
#include "Core/Game.h"

// Export function to create game instance
extern "C" {
#if defined(_WIN32)
    __declspec(dllexport)
#elif defined(__linux__) || defined(__APPLE__)
    __attribute__((visibility("default")))
#endif
    int GameEntry() {

        auto* engineContext = VoxCore::VoxCoreEngine::CreateContext();
        VoxCore::VoxCoreEngine::SetActive(*engineContext);
        engineContext->SetWindowBacked(VoxCore::Window::WindowBackend::SDL3)->
        SetRenderBackend(VoxCore::Render::RenderBackend::Vulkan)->
        Initialize();

        auto* gameContext = new MyVoxelGame();
        engineContext->RunGame(gameContext);
        engineContext->Shutdown();
        return 0;
    }
}