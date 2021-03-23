cmake_minimum_required(VERSION 3.0.0)
project(ComplexQuiz VERSION 0.1.0)

include(CTest)

set(CMAKE_CXX_STANDARD 14)
set(SRC ./src)
set(INC ./inc)

# link_directories(PUBLIC ${INC}/)




add_library(COMP ${INC}/Complex.hpp ${SRC}/Complex.cpp)
target_include_directories(COMP PUBLIC ${INC})

add_library(EXPR ${INC}/Expression.hpp ${SRC}/Expression.cpp ${COMP})
target_include_directories(EXPR PUBLIC ${INC})

add_library(QUIZ ${INC}/Quiz.hpp ${SRC}/Quiz.cpp ${COMP} ${EXPR})
target_include_directories(QUIZ PUBLIC ${INC})

add_library(STAT ${INC}/Statistics.hpp ${SRC}/Statistics.cpp)
target_include_directories(STAT PUBLIC ${INC})

add_executable(${PROJECT_NAME} ${SRC}/main.cpp  ${SRC}/Statistics.cpp ${QUIZ} ${COMP} ${EXPR})
target_include_directories(${PROJECT_NAME} PUBLIC ${INC})



target_link_libraries(${PROJECT_NAME}   COMP EXPR QUIZ)

set(FLAGS -Wall -pedantic)
target_compile_options(${PROJECT_NAME}      PRIVATE ${FLAGS})
