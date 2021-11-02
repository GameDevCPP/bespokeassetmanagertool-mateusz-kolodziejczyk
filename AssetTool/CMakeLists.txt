cmake_minimum_required(VERSION 3.20)
project(AssetTool)

set(CMAKE_CXX_STANDARD 14)
#set(SFML_DIR "D:/SFML/lib/cmake/SFML")
set(TGUI_DIR "/home/mk/Documents/TGUI-0.9.1/build")
find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED)
find_package(TGUI 0.9 REQUIRED)
add_executable(AssetTool main.cpp )
target_link_libraries(AssetTool sfml-system sfml-window sfml-graphics sfml-network sfml-audio tgui)
