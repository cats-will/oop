cmake_minimum_required(VERSION 3.17)
project(oop4)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop4 main.cpp Backup.cpp Backup.h RestorePoint.cpp RestorePoint.h StorageAlgorithm.cpp StorageAlgorithm.h CleanupAlgorithm.cpp CleanupAlgorithm.h)

set(Boost_INCLUDE_DIR C:\\Users\\AStr\\boost_1_74_0)
set(Boost_LIBRARY_DIR C:\\Users\\AStr\\boost_1_74_0\\stage\\lib)

find_package(Boost 1.74.0)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find Boost!")
endif()
include_directories(${Boost_INCLUDE_DIR})