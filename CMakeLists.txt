cmake_minimum_required(VERSION 3.30)
project(SFML_Tutorial)

set(CMAKE_CXX_STANDARD 20)

add_executable(SFML_Tutorial main.cpp
        gamedata/Game.cpp
        gamedata/Game.h
        gamedata/Config.h
        BallCollision/Engine.cpp
        BallCollision/Engine.h
        Programs/BallCollision.cpp
        Programs/BallCollision.h
        BallCollision/Config.h
        BallCollision/Ball.cpp
        BallCollision/Ball.h
)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Determine build configuration
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(LIBS ${CMAKE_SOURCE_DIR}/lib/libsfml-graphics-d.a
            ${CMAKE_SOURCE_DIR}/lib/libsfml-window-d.a
            ${CMAKE_SOURCE_DIR}/lib/libsfml-system-d.a)
    set(DLLS ${CMAKE_SOURCE_DIR}/bin/sfml-graphics-d-2.dll
            ${CMAKE_SOURCE_DIR}/bin/sfml-window-d-2.dll
            ${CMAKE_SOURCE_DIR}/bin/sfml-system-d-2.dll)
else()
    set(LIBS ${CMAKE_SOURCE_DIR}/lib/libsfml-graphics.a
            ${CMAKE_SOURCE_DIR}/lib/libsfml-window.a
            ${CMAKE_SOURCE_DIR}/lib/libsfml-system.a)
    set(DLLS ${CMAKE_SOURCE_DIR}/bin/sfml-graphics-2.dll
            ${CMAKE_SOURCE_DIR}/bin/sfml-window-2.dll
            ${CMAKE_SOURCE_DIR}/bin/sfml-system-2.dll)
endif()

# Link libraries
target_link_libraries(SFML_Tutorial ${LIBS})

# Copy DLLs after build
set(OUTPUT_DIR $<TARGET_FILE_DIR:SFML_Tutorial>)
add_custom_command(
        TARGET SFML_Tutorial POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${DLLS} ${OUTPUT_DIR}
        COMMENT "Copying runtime DLLs to target directory"
)
