cmake_minimum_required(VERSION 3.10)
 
project(SHM_2077)

set(FILES
    alcohol.cpp
    cargo.cpp
    coordinates.cpp
    fruit.cpp 
    island.cpp
    item.cpp 
    map.cpp
    player.cpp
    ship.cpp
    store.cpp
    time.cpp
    )

set(FLAGS 
    -Wall 
    #-Wextra 
    -Wpedantic 
    -Wconversion 
    -O0)

add_executable(${PROJECT_NAME} main.cpp ${FILES})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})