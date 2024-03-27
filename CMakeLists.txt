cmake_minimum_required(VERSION 3.12)

project(pong)

find_package(Qt6 COMPONENTS Core Gui Widgets)

include_directories(src)

qt_wrap_cpp(SOURCES src/aux.h)

add_executable(pong src/main.cpp src/GameLoop.cpp ${SOURCES})

target_link_libraries(pong Qt6::Core Qt6::Gui Qt6::Widgets)
