cmake_minimum_required(VERSION 3.6)
project(BananaPi_MFRC522)

set(CMAKE_CXX_STANDARD 11)

find_package (Threads)
find_library(wiringPi REQUIRED)

set(SOURCE_FILES main.cpp MFRC522.cpp MFRC522.h)
add_executable(BananaPi_MFRC522 ${SOURCE_FILES})
target_link_libraries(BananaPi_MFRC522 /usr/local/lib/libwiringPi.so)
target_link_libraries(BananaPi_MFRC522 ${CMAKE_THREAD_LIBS_INIT})