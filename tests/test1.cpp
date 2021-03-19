#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Complex.hpp"
TEST_CASE("0. test Complex construct round"){
    Complex x(0.10004,  5.00255);
    Complex z(0.1000,   5.0026);
    CHECK(x == z);
}

TEST_CASE("1. test Complex construct round"){
    Complex x(0.10004,  5.00255);
    Complex z(0.1000,   5.0026);
    CHECK(x == z);
}
TEST_CASE("2. test Complex sum"){
    Complex x(0.00009, 0.00009);
    Complex y(1.00062, 1.00068);
    Complex z(1.0007,  1.0008);
    CHECK(x+y == z);
}
TEST_CASE("3. test Complex sub"){
    Complex x(-1.00003, 3.02685);
    Complex y(0, 3);
    Complex z(-1, 0.0269);
    CHECK(x-y == z);
}
TEST_CASE("4. test Complex mul"){
    Complex x(0.00008, 1.00002);
    Complex y(1, 2);
    Complex z(-1.9999, 1.0002);
    CHECK(x*y == z);
}
TEST_CASE("5. test Complex Conjugate"){
    Complex x(-1, 3);
    Complex y(-1, -3);
    Complex z(x.Conjugate(x));
    CHECK(z == y);
}
TEST_CASE("6. test Complex Conjugate for im = 0"){
    Complex x(-1, 0);
    Complex y(-1, 0);
    Complex z(x.Conjugate(x));
    CHECK(z == y);
}
TEST_CASE("7. test Complex Module^2"){
    Complex x(-4, 3);
    double y = 25;
    double z = pow(x.Module(x), 2);
    CHECK( z == y);
}
TEST_CASE("8. test Complex div by scalar"){
    Complex x(2, 2);
    double y = -2;
    Complex z(-1, -1);
    CHECK(z == x/y);
}
TEST_CASE("9. test Complex div (2+2i)/(1+2i)"){
    Complex x(2, 2);
    Complex y(1, 2);
    Complex z(1.2, -0.4);
    CHECK(z == x/y);
}
TEST_CASE("10. test Complex div (2+2i)/(0+0i)"){
    Complex x(2, 2);
    Complex y(0.00002, 0.000035);
    CHECK_THROWS_AS(x/y, std::domain_error);
}
TEST_CASE("11. test Complex Multiplar by scalar"){
    Complex x(2, -0);
    Complex y(-1, 1);
    Complex z(-2, 2);
    CHECK(x*y == z);
}

TEST_CASE("12. test Complex input operator (2-6i)"){
    // oczekiwany wynik
    std::string expected = "(2-6i)";
    // buffor do zapisu strumienia
    std::stringstream buffer;
    // nie czaje tego, jakieś przekierowanie
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // konstruktor LZesp
    Complex x(2, -6);
    std::cout << x;

    // zmiana bufora na string 
    std::string text = buffer.str();
    // dziwna rzecz bez tego jest segm
    std::cout.rdbuf(prevcoutbuf);
    CHECK(text == expected);
}
TEST_CASE("13. test Complex input operator (-6i)"){
    // oczekiwany wynik
    std::string expected = "(-6i)";
    // buffor do zapisu strumienia
    std::stringstream buffer;
    // nie czaje tego, jakieś przekierowanie
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // konstruktor LZesp
    Complex x(0, -6);
    std::cout << x;

    // zmiana bufora na string 
    std::string text = buffer.str();
    // dziwna rzecz bez tego jest segm
    std::cout.rdbuf(prevcoutbuf);
    CHECK(text == expected);
}
TEST_CASE("14. test Complex input operator (-i)"){
    // oczekiwany wynik
    std::string expected = "(-i)";
    // buffor do zapisu strumienia
    std::stringstream buffer;
    // nie czaje tego, jakieś przekierowanie
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // konstruktor LZesp
    Complex x(0, -1);
    std::cout << x;

    // zmiana bufora na string 
    std::string text = buffer.str();
    // dziwna rzecz bez tego jest segm
    std::cout.rdbuf(prevcoutbuf);
    CHECK(text == expected);
}
// TEST_CASE("15. test Complex input operator (2+0i), should be error"){
//     // oczekiwany wynik
//     Complex y(0, -1);
//     // buffor do zapisu strumienia
//     std::stringstream buffer;
//     // nie czaje tego, jakieś przekierowanie
//     std::streambuf* prevcoutbuf = std::cin.rdbuf(buffer.rdbuf());

//     // konstruktor LZesp
//     std::string input = "(i)";
//     std::cin >> input;

//     // zmiana bufora na string 
//     std::string text = buffer.str();
//     // dziwna rzecz bez tego jest segm
//     std::cout.rdbuf(prevcoutbuf);
//     CHECK(text == expected);
// }