cmake_minimum_required(VERSION 3.0.0)
project(ComplexQuiz VERSION 0.1.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build/) 
set(CMAKE_CXX_STANDARD 14)
# Source directory .cpp files
set(SRC ./src)
# Include directory .h files
set(INC ./inc)

# Build Complex library
add_library(COMP ${INC}/Complex.hpp ${SRC}/Complex.cpp)
target_include_directories(COMP PUBLIC ${INC})

# Build Expression library
add_library(EXPR ${INC}/Expression.hpp ${SRC}/Expression.cpp ${COMP})
target_include_directories(EXPR PUBLIC ${INC})

# Build Quiz library
add_library(QUIZ ${INC}/Quiz.hpp ${SRC}/Quiz.cpp ${COMP} ${EXPR})
target_include_directories(QUIZ PUBLIC ${INC})

# Build Statistics Library
add_library(STAT ${INC}/Statistics.hpp ${SRC}/Statistics.cpp)
target_include_directories(STAT PUBLIC ${INC})

# Build main function
add_executable(${PROJECT_NAME} ${SRC}/main.cpp  ${SRC}/Statistics.cpp ${QUIZ} ${COMP} ${EXPR})
target_include_directories(${PROJECT_NAME} PUBLIC ${INC})
target_link_libraries(${PROJECT_NAME} COMP EXPR QUIZ)

# Set compile flags
set(FLAGS -Wall -pedantic)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})


# =============================[TESTS]============================
# Download doctest
include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add(
    doctest
    PREFIX ${CMAKE_BINARY_DIR}/doctest
    GIT_REPOSITORY https://github.com/onqtam/doctest.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)

# Expose required variable (DOCTEST_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(doctest source_dir)
set(DOCTEST_INCLUDE_DIR ${source_dir}/doctest CACHE INTERNAL "Path to include folder for doctest")

# Build tests
set(TEST ./test/)
add_executable(${PROJECT_NAME}-ut  ${TEST}/test0.cpp ${TEST}/test1.cpp ${TEST}/test2.cpp ${TEST}/test3.cpp ${TEST}/test4.cpp )
target_include_directories(${PROJECT_NAME}-ut PUBLIC ${DOCTEST_INCLUDE_DIR} ${INC})
target_link_libraries(${PROJECT_NAME}-ut PUBLIC  COMP EXPR QUIZ STAT)

# Set compile flags
target_compile_options(${PROJECT_NAME}-ut   PUBLIC ${FLAGS})




