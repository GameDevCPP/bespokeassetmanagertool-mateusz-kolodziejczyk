cmake_minimum_required(VERSION 3.20)
project(AssetTool)

set(CMAKE_CXX_STANDARD 14)
#set(SFML_DIR "D:/SFML/lib/cmake/SFML")
set(TGUI_DIR "/home/mk/Documents/TGUI-0.9.1/build")
find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED)
find_package(TGUI 0.9 REQUIRED)
include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.10.4)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(AssetTool main.cpp )
target_link_libraries(AssetTool PRIVATE
        sfml-system sfml-window sfml-graphics sfml-network sfml-audio
        tgui
        nlohmann_json::nlohmann_json)
