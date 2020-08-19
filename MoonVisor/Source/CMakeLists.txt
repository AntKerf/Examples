cmake_minimum_required(VERSION 2.8.12)

project(MoonVisor LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set (CMAKE_PREFIX_PATH "G:/QT/5.10.0/mingw53_32")
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc" "basetelescope.cpp" "refractortelescope.cpp" "basetelescope.h" "refractortelescope.h")

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)

set(CMAKE_BUILD_TYPE Release)
