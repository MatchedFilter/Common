cmake_minimum_required(VERSION 3.16)

project(MFByteStreamLib)

file(GLOB_RECURSE MFBYTESTREAM_LIB_SRCS src/*.cpp)

add_library(${PROJECT_NAME} INTERFACE
    ${MFBYTESTREAM_LIB_SRCS}
)

target_include_directories(${PROJECT_NAME} INTERFACE include)

target_link_libraries(${PROJECT_NAME} INTERFACE
    MFBufferLib
    MFEndianUtilsLib
)
