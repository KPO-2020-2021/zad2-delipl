/**
 * @brief   Library to use Expressions as questions
 * @author  Jakub Delicat
 * @version 1.0v
 * @date    28.03.2021r.
 */

#ifndef QUIZDATABASE_HPP
#define QUIZDATABASE_HPP
#include "Expression.h"
#include <vector>

/**
 * @brief Class with Expression database. Use to make quiz for picking Expressions.
 */
class Quiz {

    /**
     * @brief Name of Quiz.
     */
    std::string testName;

    /**
     * @brief Vector with list of questions for Quiz
     */
    std::vector<Expression> questions;

    unsigned int index;

public:

    /**
     * @brief Construct a new Quiz object.
     * @param name Name of .dat file to read questions.
     */
    Quiz(std::string name);

    /**
     * @brief Acces to size of questions vector.
     * @return Number of read questions.
     */
    unsigned int size() const;

    /**
     * @brief Acces to question on place.
     * @param int Index of read question.
     * @return Read Expression 
     */
    Expression operator[](unsigned int) const;
};

#endif
