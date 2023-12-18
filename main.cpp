#include <iostream>
#include <vector>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using json = nlohmann::json;

std::string getTrimmedString(std::string str, const std::string &whiteSpaces = " \r\n\t\v\f") {
    auto start = str.find_first_not_of(whiteSpaces);
    str.erase(0, start);
    auto end = str.find_last_not_of(whiteSpaces);
    str.erase(end + 1);

    return str;
}

void setHtmlCollection(const std::string &tag, const std::string &htmlString, std::vector<string> &collection) {
    const string openTag = "<" + tag + ">";
    const string closeTag = "</" + tag + ">";
    unsigned long long int start = 0;

    while (true) {
        auto begin = htmlString.find(openTag, start);
        if (begin != std::string::npos) {
            begin += openTag.length();
            auto end = htmlString.find(closeTag, begin);
            if (end != std::string::npos) {
                start = end;
                auto line = getTrimmedString(htmlString.substr(begin, end - begin));
                if (!line.empty()) {
                    collection.emplace_back(line);
                }
            }
            else { break; }
        }
        else { break; }
    }
}

int main() {
    cpr::Url URL{R"(https://httpbin.org/html)"};
    cpr::Header Header{{"content-type", "text/html"}};
    cpr::Response r{cpr::Get(URL, Header)};

    if (r.status_code == 200) {
        auto page = r.text;

        vector<string> collection;
        const string tag = "h1";

        setHtmlCollection(tag, page, collection);

        if (!collection.empty()) {
            cout << "FOUND (" << tag << "):" << endl;
            for (const auto &line : collection) { cout << line << endl; }
        }
        else { cout << "Tag (" << tag << ") not found" << endl; }
    }
    else { std::cerr << r.error.message << endl; }

    return 0;
}
