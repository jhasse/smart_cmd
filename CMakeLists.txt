cmake_minimum_required(VERSION 3.8)

project(smart_cmd LANGUAGES CXX)

add_executable(smart_cmd src/path.cpp src/cmd.cpp src/cmd.rc)
