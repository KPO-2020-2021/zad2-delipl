#ifndef TESTRUNNER_CPP
    #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
    #include "doctest.h"
    #include <cmath>
#endif
#include "Expression.hpp"

TEST_CASE("1. Operator create"){  
    CHECK_NOTHROW(Operator op = Operator::Op_Add);
}
TEST_CASE("2. Operator input/output operator "){
    Operator op;
    std::istringstream in("-");
    in >> op;
    std::ostringstream out;
    out << op;
    CHECK(out.str() == "-");
}
TEST_CASE("3. Operator input/output operator throw error"){
    Operator op;
    std::istringstream in("%");
    CHECK_THROWS(in >> op);
}
TEST_CASE("4. Expression default constructor"){
    CHECK_NOTHROW(Expression exp);
}
TEST_CASE("5. Expression constructor with 2 Complex"){  
    Complex x(5,-3);
    Complex y(9, -69);
    Expression exp(x, Operator::Op_Div,y);
    CHECK((exp.Arg1() == x && exp.Arg2() == y && exp.Op() == Operator::Op_Div) == true);
}
TEST_CASE("6. Expression Copying constructor"){  
    Complex x(5,-3);
    Complex y(9, -69);
    Expression exp(x, Operator::Op_Div,y);
    Expression z(exp);
    CHECK(exp == z);
}
TEST_CASE("7. Expression Calculate function"){  
    Complex x(0.00006,2);
    Complex y(0.6, 2);
    Expression exp(x, Operator::Op_Mul,y);
    Complex z(exp.Calculate());
    Complex w(-3.9999, 1.2001);
    CHECK(w == z);
}
TEST_CASE("8. Expression input/output operator (0.00006+2i)*(0.5+2i)"){
    Expression x;
    std::istringstream in("(0.00006+2i)*(0.5+2i)");
    in >> x;
    std::ostringstream out;
    out << x;
    CHECK(out.str() == "(0.0001+2i)*(0.5+2i)");
}
TEST_CASE("9. Expression input/output operator (0.00006+2i)*"){
    Expression x;
    std::istringstream in("(0.00006+2i)*");
    CHECK_THROWS(in >> x);
}
TEST_CASE("10. Expression input/output operator *(0.00006+2i)"){
    Expression x;
    std::istringstream in("*(0.00006+2i)");
    CHECK_THROWS(in >> x);
}
TEST_CASE("10. Expression input/output operator (0.00006+2i)(0.00006+2i)"){
    Expression x;
    std::istringstream in("(0.00006+2)(0.00006+2)");
    CHECK_THROWS(in >> x);
}