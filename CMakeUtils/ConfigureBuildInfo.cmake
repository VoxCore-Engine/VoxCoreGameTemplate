include(CMakeUtils/Platform.cmake)

function(configure_engine_info)

    configure_file(
            ${CMAKE_SOURCE_DIR}/CMakeUtils/Templates/EngineInfo.h.in
            ${CMAKE_SOURCE_DIR}/Engine/Public/Core/EngineInfo.h
            @ONLY
    )

    message(STATUS "EngineInfo.h configured successfully")
    message(STATUS "  Build Type: ${BUILD_TYPE}")
    message(STATUS "  Engine Version: ${ENGINE_VERSION}")
endfunction()

function(configure_game_info)

    configure_file(
            ${CMAKE_SOURCE_DIR}/CMakeUtils/Templates/GameInfo.h.in
            ${CMAKE_SOURCE_DIR}/Game/Public/Core/GameInfo.h
            @ONLY
    )

    message(STATUS "GameInfo.h configured successfully")
    message(STATUS "  Build Type: ${BUILD_TYPE}")
    message(STATUS "  Game Version: ${GAME_VERSION}")
endfunction()