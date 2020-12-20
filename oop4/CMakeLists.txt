cmake_minimum_required(VERSION 3.17)
project(oop4new)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop4new main.cpp FullRestorePoint.cpp FullRestorePoint.h DeltaRestorePoint.cpp DeltaRestorePoint.h IRestorePoint.cpp IRestorePoint.h Storage.cpp Storage.h BackUp.cpp BackUp.h RP_Creator.cpp RP_Creator.h Delta_RP_Creator.cpp Delta_RP_Creator.h Full_RP_Creator.cpp Full_RP_Creator.h)

find_package(Boost REQUIRED filesystem)

target_link_libraries(oop4new ${Boost_LIBRARIES})
