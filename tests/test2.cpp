#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Expression.hpp"

// TEST_CASE("1. Init Quiz latwe"){
//     // oczekiwany wynik
//     std::string expected = "(2-6i)";
//     Complex x;
//     // buffor do zapisu strumienia
//     std::stringstream buffer;
//     // nie czaje tego, jakieś przekierowanie
//     std::streambuf* prevcoutbuf = std::cout.rdbuf(setbuffer.rdbuf());

//     // konstruktor LZesp
//     Complex x(2, -6);
//     std::cout << x;

//     // zmiana bufora na string 
//     std::string text = buffer.str();
//     // dziwna rzecz bez tego jest segm
//     std::cout.rdbuf(prevcoutbuf);
//     CHECK(text == expected);
// }