cmake_minimum_required(VERSION 3.10)

# set the project name
project(Snake)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# add the executable
add_executable(Snake 
                main.cpp game.cpp snake.cpp apple.cpp)

target_link_libraries(Snake ${CURSES_LIBRARIES})