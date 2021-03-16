#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include <iostream>

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    Complex x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 3") {
    Complex x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
    
    
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    Complex x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("Test Complex dzielenie przez Complex") {
    Complex x;
    Complex y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 2;
 
   WARN_THROWS(x/y);
}

