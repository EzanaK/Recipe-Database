cmake_minimum_required(VERSION 3.17)
project(Recipe_Database C)

set(CMAKE_C_STANDARD 99)

add_executable(Recipe_Database Recipe_Database.c Recipe.h Database_Functions.c)