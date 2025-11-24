cmake_minimum_required(VERSION 3.16)

project(SceneGraph LANGUAGES CXX)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core Quick Qml OpenGL)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick Qml OpenGL)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(SceneGraph
    main.cpp
    resources.qrc
    qpaintclockcircle.h qpaintclockcircle.cpp
    qsgclockcircle.h qsgclockcircle.cpp
    clockcirclebackend.h clockcirclebackend.cpp
    registeration.h
    utils.h
)

target_link_libraries(SceneGraph PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::OpenGL
)
target_link_libraries(SceneGraph PRIVATE Qt6::Quick)
target_link_libraries(SceneGraph PRIVATE Qt6::Core)

