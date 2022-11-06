cmake_minimum_required(VERSION 3.10)

project(Sasm VERSION 1.0)

add_executable(sasm sasm.cpp)

add_library(Symbol OBJECT Symbol.cpp)
add_library(SymList OBJECT SymList.cpp)
add_library(SymTab OBJECT SymTab.cpp)
add_library(utils OBJECT utils.cpp)

target_link_libraries(sasm Symbol SymList SymTab utils)
#target_link_libraries(SymTab Symbol utils)
#target_link_libraries(SymList Symbol SymTab utils)
