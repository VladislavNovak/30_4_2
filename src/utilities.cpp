#include "../headers/utilities.h"

std::string getTrimmedString(std::string str, const std::string &whiteSpaces) {
    auto start = str.find_first_not_of(whiteSpaces);
    str.erase(0, start);
    auto end = str.find_last_not_of(whiteSpaces);
    str.erase(end + 1);

    return str;
}

void setHtmlCollection(const std::string &tag, const std::string &htmlString, std::vector<std::string> &collection) {
    const std::string openTag = "<" + tag + ">";
    const std::string closeTag = "</" + tag + ">";
    unsigned long long int start = 0;

    while (true) {
        auto begin = htmlString.find(openTag, start);
        if (begin != std::string::npos) {
            // Начало контента
            begin += openTag.length();
            auto end = htmlString.find(closeTag, begin);
            if (end != std::string::npos) {
                start = end;
                // Конец контента
                auto endContent = end - begin;
                auto line = getTrimmedString(htmlString.substr(begin, endContent));
                if (!line.empty()) {
                    collection.emplace_back(line);
                }
            }
            else { break; }
        }
        else { break; }
    }
}