cmake_minimum_required(VERSION 3.10)


set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

add_executable(
	main
	Main/main.cpp
	Main/Menu.cpp
	Main/InfoFromFile.cpp
	Main/StudentaiInfo.cpp
	Main/Tests.cpp
	Main/TestFileRead.cpp
	Main/TestFileWrite.cpp
	Main/GenerateTestFile.cpp
	Main/Headers/StudentaiInfo.h
	Main/Headers/Timer.h
	Main/Headers/Menu.h
	Main/Headers/InfoFromFile.h
	Main/Headers/Tests.h
	Main/Headers/TestFileRead.h
	Main/Headers/TestFileWrite.h
	Main/Headers/GenerateTestFile.h
)