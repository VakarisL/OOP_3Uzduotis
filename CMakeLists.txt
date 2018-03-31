cmake_minimum_required(VERSION 3.4)


set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

add_executable(
	main
	Main/main.cpp
	Main/Menu.cpp
	Main/InfoFromConsole.cpp
	Main/InfoFromRNG.cpp
	Main/FileInput.cpp
	Main/RandomInput.cpp
	Main/MathFunctions.cpp
	Main/ConsoleOutput.cpp
	Main/Headers/StudentaiInfo.h
	Main/Headers/Menu.h
	Main/Headers/InfoFromConsole.h
	Main/Headers/InfoFromRNG.h
	Main/Headers/FileInput.h
	Main/Headers/RandomInput.h
	Main/Headers/MathFunctions.h
	Main/Headers/ConsoleOutput.h
)