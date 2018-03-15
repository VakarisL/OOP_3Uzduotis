cmake_minimum_required(VERSION 3.4)


set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

add_executable(
	main
	Main/main.cpp
	Main/FileInput.cpp
	Main/ConsoleInput.cpp
	Main/RandomInput.cpp
	Main/MathFunctions.cpp
	Main/ConsoleOutput.cpp
	Main/Headers/FileInput.h
	Main/Headers/ConsoleInput.h
	Main/Headers/RandomInput.h
	Main/Headers/MathFunctions.h
	Main/Headers/ConsoleOutput.h
)