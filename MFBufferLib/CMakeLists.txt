cmake_minimum_required(VERSION 3.16)

project(MFBufferLib)

file(GLOB_RECURSE MFBUFFER_LIB_SRCS src/*.cpp)

add_library(${PROJECT_NAME} INTERFACE
    ${MFBUFFER_LIB_SRCS}
)

target_include_directories(${PROJECT_NAME} INTERFACE include)
