#ifndef TESTRUNNER_CPP
    #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
    #include "doctest.h"
    #include <cmath>
#endif
#include "Statistics.h"
TEST_CASE("1. Statistics constructor"){
    CHECK_NOTHROW(Statistics s);
}
TEST_CASE("2. Statistics operator++"){
    Statistics s;
    s++;
    CHECK((s.Count() == 1 && s.CountCorrect() == 1));
}
TEST_CASE("3. Statistics operator--"){
    Statistics s;
    s++;
    s++;
    s++;
    s--;
    CHECK((s.Count() == 4 && s.CountCorrect() == 3));
}
TEST_CASE("4. Statistics Calculate"){
    Statistics s;
    for(int i = 0; i < 10; i++){
        if((rand() +i) % 3 > 1)
            s++;
        else
            s--;
    }
    CHECK(s.Calculate() == 100 * s.CountCorrect()/s.Count());
}