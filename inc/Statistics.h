#ifndef STATISTICS_HPP
#define STATISTICS_HPP
#include <iostream>
/**
 * @brief Class to provide statistics
 */
class Statistics{
    /**
     * @brief Number of correct events
     */
    unsigned int correctEvents;

    /**
     * @brief Number of events
     */
    unsigned int quantity;

    public:

    /**
     * @brief Construct a new Statistics object 
     */
    Statistics();

    /**
     * @brief Access to @a correctEvents
     * @return Number of correct events 
     */
    unsigned int CountCorrect() const { return correctEvents;}

    /**
     * @brief Access to @a quantity
     * @return Number of events
     */
    unsigned int Count() const { return quantity;}

    /**
     * @brief Calculate percent of good events
     * @return Percent of correct events
     */
    double Calculate() const;
    
    /**
     * @brief Add correct event
     */
    unsigned int operator++(int);

    /**
     * @brief Add wrong answer
     */
    unsigned int operator--(int);

};

/**
 * @brief Print results of providing statistics
 * @return std::ostream& output stream
 */
std::ostream& operator<<(std::ostream&, const Statistics&);
#endif
