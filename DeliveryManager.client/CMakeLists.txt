cmake_minimum_required(VERSION 3.10)

project(SandBox)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

enable_testing()

set(CURL_LIBRARY "-lcurl") 
find_package(CURL REQUIRED) 
include_directories(${CURL_INCLUDE_DIR})

set(SOURCES
    src/dummy.cpp
    src/curl_helper.cpp)

set(TESTS
    tests/dummy.ut.cpp)

set(FLAGS -Wall -Wextra -pedantic -Wconversion -Werror -O3 -std=c++17)

include_directories(inc)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib ${CURL_LIBRARIES})

add_executable(${PROJECT_NAME}-ut ${TESTS})

target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut
         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
