cmake_minimum_required(VERSION 3.16)

project(Copies LANGUAGES CXX)

add_executable(Copies main.cpp
    Base.h
    ItemBase.h
    Derrived.h)

target_link_libraries(Copies Qt${QT_VERSION_MAJOR}::Core  Qt${QT_VERSION_MAJOR}::Widgets)
