#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test Complex sum"){
    Complex x(-1, 3);
    Complex y(3, 0);
    Complex z(2, 3);
    CHECK(x+y == z);
}
TEST_CASE("test Complex sub"){
    Complex x(-1, 3);
    Complex y(-1, 5);
    Complex z(0, -2);
    CHECK(x-y == z);
}
TEST_CASE("test Complex mul"){
    Complex x(2, 1);
    Complex y(-1, 2);
    Complex z(-4.0, 3.0);
    CHECK(x*y == z);
}
TEST_CASE("test Complex Conjugate"){
    Complex x(-1, 3);
    Complex y(-1, -3);
    Complex z(x.Conjugate(x));
    CHECK(z == y);
}
TEST_CASE("test Complex Module"){
    Complex x(-4, 3);
    double y = 5;
    double z = x.Module(x);
    CHECK( z == y);
}
TEST_CASE("test Complex div"){
    Complex x(2, 2);
    Complex y(1, 2);
    Complex z(1.2, -0.4);
    std::cout <<"x:" << x <<  "y: "<<y <<"z: " <<z<< " x/y: " << x/y << std::endl;
    CHECK(z == x/y);
}

