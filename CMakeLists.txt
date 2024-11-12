cmake_minimum_required(VERSION 3.28)

project(MatrixScroll VERSION 0.1.0)

# set directory varaiables 
set(SOURCE_DIR "src/")
set(INC_DIR "inc/")

add_executable(MatScroll ${SOURCE_DIR}main.cpp ${SOURCE_DIR}colors.cpp ${INC_DIR}color.h)