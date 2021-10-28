cmake_minimum_required(VERSION 3.20)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

file(GLOB files *.cpp)
foreach(file ${files})
    string(REGEX REPLACE ".+/(.+)\\.cpp$" "\\1" filename ${file})
    add_executable (${filename} ${file})
endforeach()
