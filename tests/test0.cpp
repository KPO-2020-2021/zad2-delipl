#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include <iostream>
#define MIN_DIFF 0.0001
// function fo() is used in Complex constructor
double fo(double re){
    double x  = re;
    re = (int)(re * pow(MIN_DIFF, -1));
    re = x* pow(MIN_DIFF, -1);
    re = round(re);
    re = re * MIN_DIFF;
    return re;
}
TEST_CASE("1. Positive round up"){
    double re = fo(3.02689);
    CHECK(re == 3.0269);
}
TEST_CASE("2. Negative round up"){
    double re = fo(-5.99996);
    CHECK(re == -6);
}
TEST_CASE("3. Positive round down"){
    double re = fo(5.99992);
    CHECK(re == 5.9999);
}
TEST_CASE("4. Negative round down"){
    double re = fo(-5.99992);
    CHECK(re == -5.9999);
}
TEST_CASE("5. Positive round to next times"){
    double re = fo(5.44999);
    CHECK(re == 5.45);
}
TEST_CASE("6. Negative round to next times"){
    double re = fo(-5.44999);
    CHECK(re == -5.45);
}