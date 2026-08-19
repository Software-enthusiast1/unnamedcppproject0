cmake_minimum_required(VERSION 3.16)
project(unnamedproject LANGUAGES  CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
	raylib
	GIT_REPOSITORY https://github.com/raysan5/raylib
	GIT_TAG        master
)
set(OPENGL_VERSION "ES 2.0" CACHE STRING "OpenGL version" FORCE)
FetchContent_MakeAvailable(raylib)

add_executable(MyGame src/main.cpp)

target_link_libraries(MyGame PRIVATE raylib)
