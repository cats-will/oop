cmake_minimum_required(VERSION 3.17)
project(oop4)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop4 main.cpp Backup.cpp Backup.h RestorePoint.cpp RestorePoint.h StorageAlgorithm.cpp StorageAlgorithm.h RP_Builder.h)

find_package(Boost REQUIRED filesystem)

target_link_libraries(oop4 ${Boost_LIBRARIES})
