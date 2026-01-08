
add_executable(${LAUNCHER_NAME}
    src/main.cpp
)

set_target_properties(${LAUNCHER_NAME} PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(${LAUNCHER_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${LAUNCHER_NAME} PRIVATE VoxCore)

add_dependencies(${LAUNCHER_NAME} VoxCore ${GAME_NAME})

set_target_properties(${LAUNCHER_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)