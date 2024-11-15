cmake_minimum_required(VERSION 3.28)

project(MatrixScroll VERSION 0.1.0)

# set directory varaiables 
set(SOURCE_DIR "src/")
set(INC_DIR "inc/")

find_package(Boost 1.86 COMPONENTS program_options REQUIRED)
add_executable(MatScroll ${SOURCE_DIR}main.cpp ${SOURCE_DIR}colors.cpp ${SOURCE_DIR}term_window.cpp ${SOURCE_DIR}line.cpp ${INC_DIR}color.h ${INC_DIR}term_window.h ${INC_DIR}line.h)
target_link_libraries(MatScroll Boost::program_options)