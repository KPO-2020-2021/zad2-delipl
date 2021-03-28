#ifndef TESTRUNNER_CPP
    #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
    #include "doctest.h"
    #include <cmath>
#endif

#include "Complex.h"
TEST_CASE("1. Complex default constructor round"){
    CHECK_NOTHROW(Complex x);
}
TEST_CASE("2. Complex constructor round"){
    Complex x(0.10004,  5.00255);
    Complex z(0.1000,   5.0026);
    CHECK(x == z);
}

TEST_CASE("3. Complex constructor round"){
    Complex x(0.10004,  5.00255);
    Complex z(0.1000,   5.0026);
    CHECK(x == z);
}
TEST_CASE("4. Complex copying constructor round"){
    Complex x(0.10004,  5.00255);
    Complex z(0.1000,   5.0026);
    Complex y(z);
    CHECK(x == y);
}
TEST_CASE("5. Complex Re() and Im()"){
    Complex x(0.10004,  5.00255);
    CHECK((x.Re() == 0.1 && x.Im() == 5.0026) == 1);
}
TEST_CASE("6. Complex sum"){
    Complex x(0.00009, 0.00009);
    Complex y(1.00062, 1.00068);
    Complex z(1.0007,  1.0008);
    CHECK(x+y == z);
}
TEST_CASE("7. Complex sub"){
    Complex x(-1.00003, 3.02685);
    Complex y(0, 3);
    Complex z(-1, 0.0269);
    CHECK(x-y == z);
}
TEST_CASE("8. Complex -complex"){
    Complex y(0, 3);
    Complex z(0, -3.00003);
    CHECK(-y == z);
}
TEST_CASE("10. Complex mul by double"){
    Complex x(0.00003, 1.00002);
    double z = -2;
    Complex y(0, -2);
    CHECK(x*z == y);
}
TEST_CASE("11. Complex mul by Complex"){
    Complex x(0.00008, 1.00002);
    Complex y(1, 2);
    Complex z(-1.9999, 1.0002);
    CHECK(x*y == z);
}
TEST_CASE("12. Complex Conjugate"){
    Complex x(-1, 3);
    Complex y(-1, -3);
    Complex z(x.Conjugate(x));
    CHECK(z == y);
}
TEST_CASE("13. Complex Conjugate for im = 0"){
    Complex x(-1, 0);
    Complex y(-1, 0);
    Complex z(x.Conjugate(x));
    CHECK(z == y);
}
TEST_CASE("14. Complex Module^2"){
    Complex x(-4, 3);
    double y = 25;
    double z = pow(x.Module(), 2);
    CHECK( z == y);
}
TEST_CASE("15. Complex div by scalar"){
    Complex x(2, 2);
    double y = -2;
    Complex z(-1, -1);
    CHECK(z == x/y);
}
TEST_CASE("16. Complex div by Complex"){
    Complex x(2, 2);
    Complex y(1, 2);
    Complex z(1.2, -0.4);
    CHECK(z == x/y);
}
TEST_CASE("17. Complex div by Complex (0+0i)"){
    Complex x(2, 2);
    Complex y(0.00002, 0.000035);
    CHECK_THROWS_AS(x/y, std::domain_error);
}
TEST_CASE("18. Complex input/output operator (2-6)"){
    Complex x;
    std::istringstream in("(2-6)");
    in >> x;
    std::ostringstream out;
    out << x;
    
    CHECK(out.str() == "(-4)");
}
TEST_CASE("19. Complex input/output operator (2i-6i)"){
    Complex x;
    std::istringstream in("(2i-6i)");
    in >> x;
    std::ostringstream out;
    out << x;
    
    CHECK(out.str() == "(-4i)");
}
TEST_CASE("20. Complex input/output operator warn throw (2i-6)"){
    Complex x;
    std::istringstream in("(2i-6)");
    in >> x;
    std::ostringstream out;
    out << x;
    
    CHECK(out.str() == "(-6+2i)");
}
TEST_CASE("21. Complex input/output operator (2-6i)"){
    Complex x;
    std::istringstream in("(2-6i)");
    in >> x;
    std::ostringstream out;
    out << x;
    CHECK(out.str() == "(2-6i)");
}
TEST_CASE("22. Complex input/output operator (-6i)"){
    Complex x;
    std::istringstream in("(-6i)");
    in >> x;
    std::ostringstream out;
    out << x;
    CHECK(out.str() == "(-6i)");
}
TEST_CASE("23. Complex input/output operator (i)"){
    Complex x;
    std::istringstream in("(i)");
    in >> x;
    std::ostringstream out;
    out << x;
    CHECK(out.str() == "(i)");
}
TEST_CASE("24. Complex input/output operator (-i)"){
    Complex x;
    std::istringstream in("(-i)");
    in >> x;
    std::ostringstream out;
    out << x;
    CHECK(out.str() == "(-i)");
}
TEST_CASE("25. Complex input/output operator (0.00009-i)"){
    Complex x;
    std::istringstream in("(0.00009-i)");
    in >> x;
    std::ostringstream out;
    out << x;
    CHECK(out.str() == "(0.0001-i)");
}
TEST_CASE("26. Complex input/output operator (9)"){
    Complex x;
    std::istringstream in("(-5)");
    in >> x;
    std::ostringstream out;
    out << x;
    CHECK(out.str() == "(-5)");
}
TEST_CASE("27. Complex input/output operator (-5)"){
    Complex x;
    std::istringstream in("(-5)");
    in >> x;
    std::ostringstream out;
    out << x;
    CHECK(out.str() == "(-5)");
}
TEST_CASE("28. Complex input/output operator (-5+9+6+5i-12i+33i-9i)"){
    Complex x;
    std::istringstream in("(-5+9+6+5i-12i+33i-9i)");
    in >> x;
    std::ostringstream out;
    out << x;
    CHECK(out.str() == "(10+17i)");
}
TEST_CASE("29. Complex input/output operator check throw ()"){
    Complex x;
    std::istringstream in("()");
    CHECK_THROWS(in >> x);
}
TEST_CASE("30. Complex input/output operator check throw (5c+3i)"){
    Complex x;
    std::istringstream in("(5c+3i)");
    CHECK_THROWS(in >> x);
}
TEST_CASE("31. Complex input/output operator check throw (5*3i)"){
    Complex x;
    std::istringstream in("(5*3i)");
    CHECK_THROWS(in >> x);
}
TEST_CASE("32. Complex input/output operator check throw 2+9i"){
    Complex x;
    std::istringstream in("2+9i");
    CHECK_THROWS(in >> x);
}