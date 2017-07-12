cmake_minimum_required(VERSION 3.7)

project(sdleditor)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED SDL2)
pkg_check_modules(CAIRO REQUIRED cairo)
pkg_check_modules(PANGO REQUIRED pango)
#pkg_check_modules(PANGOCAIRO REQUIRED pangocairo)

include_directories(${SDL2_INCLUDE_DIRS} ${CAIRO_INCLUDE_DIRS} ${PANGO_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(sdleditor ${SOURCE_FILES})
target_link_libraries(sdleditor ${SDL2_LIBRARIES} ${CAIRO_LIBRARIES} ${PANGO_LIBRARIES})