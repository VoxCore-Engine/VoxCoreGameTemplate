cmake_minimum_required(VERSION 3.16)

include(CMakeUtils/ConfigureBuildInfo.cmake)

project(VoxCore
    DESCRIPTION "Cross-platform game engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Project settings
set(LAUNCHER_NAME "VoxLauncher" CACHE STRING "Name of the launcher executable")
set(GAME_NAME "MyVoxelGame" CACHE STRING "Name of the game library")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build/${CMAKE_BUILD_TYPE}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build/${CMAKE_BUILD_TYPE}/lib)

vox_detect_platform(PLATFORM_NAME)
add_compile_definitions(PLATFORM_NAME="${VOX_PLATFORM}")

add_subdirectory(ThirdParty/json)

set(SDL_STATIC ON CACHE BOOL "" FORCE)
add_subdirectory(ThirdParty/SDL)


add_subdirectory(Engine)
add_subdirectory(Game)
add_subdirectory(Launcher)

target_include_directories(VoxCore PUBLIC
        ThirdParty/SDL/include
)
target_link_libraries(VoxCore PRIVATE
        SDL3-static
        nlohmann_json::nlohmann_json
)