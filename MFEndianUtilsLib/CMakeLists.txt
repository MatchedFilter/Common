cmake_minimum_required(VERSION 3.16)

project(MFEndianUtilsLib)

file(GLOB_RECURSE MFENDIANUTILS_LIB_SRCS src/*.cpp)

add_library(${PROJECT_NAME} STATIC
    ${MFENDIANUTILS_LIB_SRCS}
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
