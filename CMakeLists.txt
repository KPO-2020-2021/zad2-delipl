cmake_minimum_required(VERSION 3.0.0)
project(ComplexQuiz VERSION 0.1.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build/) 
set(CMAKE_CXX_STANDARD 14)
# Source directory .cpp files
set(SRC ./src)
# Include directory .h files
set(INC ./inc)
# Include libraries
set(LIB ./lib)

# Build Complex library
add_library(COMP ${INC}/Complex.hpp ${SRC}/Complex.cpp)
target_include_directories(COMP PUBLIC ${INC})

# Build Expression library
add_library(EXPR ${INC}/Expression.hpp ${SRC}/Expression.cpp)
target_link_libraries(EXPR COMP)
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
# Include doctest
add_subdirectory(${LIB}/doctest)
set(DOCTEST_INCLUDE_DIR ${LIB}/doctest/doctest)

# Build tests
set(TEST ./test/)

add_executable(ut0  ${TEST}/test0.cpp )
target_include_directories(ut0 PUBLIC ${DOCTEST_INCLUDE_DIR} ${INC})
target_link_libraries(ut0 PUBLIC doctest)

add_executable(ut1  ${TEST}/test1.cpp )
target_include_directories(ut1 PUBLIC ${DOCTEST_INCLUDE_DIR} ${INC})
target_link_libraries(ut1 PUBLIC COMP doctest)

add_executable(ut2  ${TEST}/test2.cpp )
target_include_directories(ut2 PUBLIC ${DOCTEST_INCLUDE_DIR} ${INC})
target_link_libraries(ut2 PUBLIC COMP EXPR doctest)

add_executable(ut3  ${TEST}/test3.cpp )
target_include_directories(ut3 PUBLIC ${DOCTEST_INCLUDE_DIR} ${INC})
target_link_libraries(ut3 PUBLIC COMP EXPR QUIZ doctest)

add_executable(ut4  ${TEST}/test4.cpp )
target_include_directories(ut4 PUBLIC ${DOCTEST_INCLUDE_DIR} ${INC})
target_link_libraries(ut4 PUBLIC STAT doctest)

# Build all tests
add_executable(ut ${TEST}/testRunner.cpp)
target_include_directories(ut PUBLIC ${DOCTEST_INCLUDE_DIR} ${INC})
target_link_libraries(ut PUBLIC COMP EXPR QUIZ STAT doctest)

