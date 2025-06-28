cmake_minimum_required(VERSION 3.16)

project(Performance LANGUAGES CXX)

add_executable(Performance
  main.cpp
  mainclass.h mainclass.cpp
  gettersetterperf.h gettersetterperf.cpp
)
target_link_libraries(Performance Qt${QT_VERSION_MAJOR}::Core)
