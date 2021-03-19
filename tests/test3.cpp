#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "QuizDataBase.hh"
TEST_CASE("1. Init Quiz latwe"){
    Quiz q("latwy");
    CHECK(1==1);
}
TEST_CASE("2. Size"){
    Quiz q("latwy");
    std::cout << "Size: "<< q.size() << std::endl;
    CHECK(1==1);
}
TEST_CASE("3. Print questions"){
    Quiz q("latwy");
    for(unsigned int i = 0; i < q.size(); i++){
        std::cout << q[i] << std::endl;
    }
    CHECK(1==1);
}
TEST_CASE("3. Print questions and calculate"){
    Quiz q("latwy");
    for(unsigned int i = 0; i < q.size(); i++){
        std::cout << q[i] << " = " << q[i].Calculate() << std::endl;
    }
    CHECK(1==1);
}