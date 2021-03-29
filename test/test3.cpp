#ifndef TESTRUNNER_CPP
    #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
    #include "doctest.h"
    #include <cmath>
#endif

#include "Quiz.h"
TEST_CASE("1. Quiz constructor and reading file latwe"){
    CHECK_NOTHROW( Quiz q("latwy"));
}
TEST_CASE("2. Quiz get size"){
    Quiz q("latwy");
    CHECK(q.size()==5);
}
void foo(Quiz &q){
    for(unsigned int i = 0; i < q.size(); i++){
        std::cout << q[i] << std::endl;
    }
}
TEST_CASE("3. Quiz print questions"){
    Quiz q("latwy");
    CHECK_NOTHROW(foo(q));
}
void goo(Quiz &q){
    for(unsigned int i = 0; i < q.size(); i++){
        std::cout << q[i] << " = " << q[i].Calculate() << std::endl;
    }
}
TEST_CASE("4. Quiz print questions and calculate"){
    Quiz q("latwy");
    CHECK_NOTHROW(goo(q));
}