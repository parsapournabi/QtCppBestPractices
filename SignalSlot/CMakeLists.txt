cmake_minimum_required(VERSION 3.16)

project(SignalSlot LANGUAGES CXX)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core Quick Qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick Qml)

add_executable(SignalSlot
    main.cpp
    resources.qrc

)

target_link_libraries(SignalSlot PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Qml
)
target_link_libraries(SignalSlot PRIVATE Qt${QT_VERSION_MAJOR}::Quick)
target_link_libraries(SignalSlot PRIVATE Qt${QT_VERSION_MAJOR}::Core)

