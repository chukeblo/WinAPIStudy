cmake_minimum_required(VERSION 3.10)
project(win_api_study CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /EHsc")

set( src_dir ${CMAKE_SOURCE_DIR}/src )
set( src_include_dir ${src_dir}/include )

add_subdirectory(${src_dir})