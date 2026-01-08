
file(GLOB_RECURSE GAME_SRC
        Private/*.cpp
        Private/**/*.cpp
)
file(GLOB_RECURSE GAME_HDR
        Public/*.h
        Public/**/*.h
)
add_library(${GAME_NAME} SHARED
        ${GAME_HDR}
        ${GAME_SRC}
)
#GAME SETTINGS
set(GAME_VERSION "0.0.1") # Define the game version

target_include_directories(${GAME_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
)
set_target_properties(${GAME_NAME} PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME ${GAME_NAME}
    PREFIX ""
)

target_link_libraries(${GAME_NAME} PRIVATE VoxCore)

configure_game_info()

set_target_properties(${GAME_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/bin
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bin
)