cmake_minimum_required(VERSION 3.16)

project(VariadicArgs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core Quick Qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick Qml)

add_executable(VariadicArgs
    main.cpp
    resources.qrc
    simpleclass.h simpleclass.cpp
    CallerClass.h

)

target_link_libraries(SignalSlot PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Qml
)
target_link_libraries(VariadicArgs PRIVATE Qt${QT_VERSION_MAJOR}::Quick)
target_link_libraries(VariadicArgs PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(VariadicArgs PRIVATE Qt${QT_VERSION_MAJOR}::Core)

