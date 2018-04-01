cmake_minimum_required(VERSION 3.4)


set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

add_executable(
	main
	Main/main.cpp
	Main/Menu.cpp
	Main/InfoFromConsole.cpp
	Main/InfoFromRNG.cpp
	Main/InfoFromFile.cpp
	Main/Tests.cpp
	Main/TestFileRead.cpp
	Main/GenerateTestFile.cpp
	Main/MathFunctions.cpp
	Main/TestFileWrite.cpp
	Main/Headers/StudentaiInfo.h
	Main/Headers/Menu.h
	Main/Headers/InfoFromConsole.h
	Main/Headers/InfoFromRNG.h
	Main/Headers/InfoFromFile.h
	Main/Headers/Tests.h
	Main/Headers/TestFileRead.h
	Main/Headers/GenerateTestFile.h
	Main/Headers/MathFunctions.h
	Main/Headers/TestFileWrite.h
)