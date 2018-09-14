cmake_minimum_required(VERSION 3.9)
FUNCTION(PREPEND var prefix)
    SET(listVar "")
    FOREACH(f ${ARGN})
        LIST(APPEND listVar "${prefix}/${f}")
    ENDFOREACH(f)
    SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(INC Includes)

set(COMMON_INC common)
set(COMMON_SDIR common)

set(NAME CountWords)

set(SDIR Srcs)

set(SOURCES
        "BinaryTreeNode.class.cpp"
        "main.cpp")
PREPEND(SOURCES_REL ${SDIR} ${SOURCES})

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")

add_executable(${NAME} ${SOURCES_REL})
target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${INC})