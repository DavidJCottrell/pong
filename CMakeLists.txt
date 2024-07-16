cmake_minimum_required(VERSION 3.22.1)
project(Pong)

if(EXISTS "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
    include("${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
else()
    message(FATAL_ERROR "Conan toolchain file not found: ${CMAKE_BINARY_DIR}/conan_toolchain.cmake. Please run 'conan install .' first.")
endif()

if (APPLE)
    execute_process(COMMAND xcrun --show-sdk-path OUTPUT_VARIABLE CMAKE_OSX_SYSROOT OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(SDL2 REQUIRED)

add_executable(Pong src/main.cpp
    src/Engine/Game.cpp
    include/Game.hpp
    src/Engine/Utils.cpp
    include/Utils.hpp
    include/Constants.hpp
    include/Entity.hpp
    src/Engine/Entities/Paddle.cpp
    include/Paddle.hpp
    src/Engine/Entities/Opponent.cpp
    include/Opponent.hpp
    src/Engine/Entities/Ball.cpp
    include/Ball.hpp
    src/Engine/Entities/Player.cpp
    include/Player.hpp
)

target_link_libraries(Pong SDL2::SDL2 SDL2::SDL2main)
