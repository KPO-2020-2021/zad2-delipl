#ifndef HEADER_HH
#define HEADER_HH

/*=============TO HEADER===============================*/
bool isSign(char c);
bool isPosSign(char c);
bool isDigit(std::string text);
/**
 * @brief Looking for double number from string
 * 
 * @param text input text to search
 * @param index first index to start search
 * @return found double number or 0.0 if didn't find
 */
double FindDoubleFromString(std::string text, int *index);
/*======================================================*/

#endif