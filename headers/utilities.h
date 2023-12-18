#ifndef INC_30_4_2_UTILITIES_H
#define INC_30_4_2_UTILITIES_H

#include <iostream>
#include <vector>

// Обрезает конечные пустые символы
std::string getTrimmedString(std::string str, const std::string &whiteSpaces = " \r\n\t\v\f");

// Добавляет контент указанного tag из htmlString в collection
void setHtmlCollection(const std::string &tag,
                       const std::string &htmlString,
                       std::vector<std::string> &collection);


#endif //INC_30_4_2_UTILITIES_H
