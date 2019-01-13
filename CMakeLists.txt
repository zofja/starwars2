cmake_minimum_required(VERSION 3.12)
project(starwars2)

set(CMAKE_CXX_STANDARD 17)
set(-DCMAKE_C_COMPILER=clang-6.0 -DCMAKE_CXX_COMPILER=clang++6.0)

add_executable(starwars2 starwars2_example.cc src/battle.cc src/helper.cc src/imperialfleet.cc src/rebelfleet.cc)
add_executable(test test0.cpp src/battle.cc src/helper.cc src/imperialfleet.cc src/rebelfleet.cc)
add_executable(tes2 test2.cc src/battle.cc src/helper.cc src/imperialfleet.cc src/rebelfleet.cc)