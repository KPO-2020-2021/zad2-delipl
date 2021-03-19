#ifndef QUIZDATABASE_HPP
#define QUIZDATABASE_HPP
#include "Expression.hpp"
#include <vector>
#include <fstream>
/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
class Quiz {
    
    std::string testName;

public:
    std::vector<Expression> questions;
    Quiz(std::string name);
    unsigned int size() const;
    Expression operator[](unsigned int) const;
};

#endif
