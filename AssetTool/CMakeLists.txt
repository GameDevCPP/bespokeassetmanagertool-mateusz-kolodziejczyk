cmake_minimum_required(VERSION 3.20)
project(AssetTool)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED)

add_executable(AssetTool main.cpp)
