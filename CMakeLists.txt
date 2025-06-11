cmake_minimum_required(VERSION 3.10)
project(BowlingGameProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Add GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(BowlingGame
    tb/tbBowlingGame.cpp
    src/Frame.cpp
    src/Player.cpp
    src/BowlingGame.cpp
)

target_include_directories(BowlingGame PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(BowlingGame GTest::GTest GTest::Main)

add_test(NAME BowlingGameTest COMMAND BowlingGame)