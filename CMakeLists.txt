cmake_minimum_required(VERSION 3.4)


set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(
	main
	Main/main.cpp
	Main/FileInput.cpp
	Main/Headers/FileInput.h
)