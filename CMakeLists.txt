cmake_minimum_required (VERSION 3.20)
project (CppAlgoDataStructPatterns)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/unit_test/*.cpp"
    )

macro( google_unit_test  filename )
    add_executable(            ${filename}  unit_test/${filename}.cpp )
    target_include_directories(${filename} PRIVATE include)
    target_link_libraries(     ${filename}  GTest::gtest_main )
    add_test(                  ${filename}  ${CMAKE_CURRENT_BINARY_DIR}/${filename} )
    include(GoogleTest)
    gtest_discover_tests(${filename})
 endmacro( google_unit_test )

FOREACH( testsource ${all_SRCS} )
    GET_FILENAME_COMPONENT( filename ${testsource} NAME_WE )
    google_unit_test( ${filename} )
 ENDFOREACH()

add_executable(cpp_algo_patterns main.cpp)
include_directories(include)