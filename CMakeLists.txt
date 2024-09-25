cmake_minimum_required(VERSION 3.29)
project(exp2)

set(CMAKE_CXX_STANDARD 11)


set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

#如果在src文件夹找到文件夹,遍历该文件夹下的所有文件，如果该文件夹下还有文件夹，递归遍历
function(retrieve_files out_files)
    set(source_list)
    foreach (dirname ${ARGN})
        file(GLOB_RECURSE files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
                "${dirname}/*.cmake"
                "${dirname}/*.h"
                "${dirname}/*.hpp"
                "${dirname}/*.c"
                "${dirname}/*.cpp"
                "${dirname}/*.cc"
        )
        foreach (filename ${files})
            list(APPEND source_list "${CMAKE_CURRENT_SOURCE_DIR}/${filename}")
            set(file_abs_path "${CMAKE_CURRENT_SOURCE_DIR}/${filename}")
            get_filename_component(source_path "${filename}" PATH)
            string(REPLACE "/" "\\" filter_dir "${source_path}")
            source_group("${filter_dir}" FILES "${filename}")
        endforeach ()
    endforeach ()
    set(${out_files} ${source_list} PARENT_SCOPE)
endfunction()


retrieve_files(SOURCES src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(exp2 ${SOURCES} main.cpp)