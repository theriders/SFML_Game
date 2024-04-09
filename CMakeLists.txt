cmake_minimum_required(VERSION 3.12)
project(2036SkeletonCmake)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/;${CMAKE_MODULE_PATH}")



find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)

include_directories(
        ${SFML_INCLUDE_DIR}
)

set(SOURCE_FILES
        main.cpp
        Game.cpp
        Game.h
        RegularGameObject.cpp
        GameObject.h
        RegularGameObject.h AnimatedGameObject.h AnimatedGameObject.cpp resource_path.h)

add_executable(2036SkeletonCmake ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})