#include <iostream>
#include <vector>
#include <cpr/cpr.h>
#include "headers/utilities.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    cpr::Url URL{R"(https://httpbin.org/html)"};
    cpr::Header Header{{"content-type", "text/html"}};
    cpr::Response r{cpr::Get(URL, Header)};

    if (r.status_code == 200) {
        auto page = r.text;

        // Будет содержать контент всех указанных тегов
        vector<string> collection;
        // Можно указать любой тег типа p, body, section и прочего
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
