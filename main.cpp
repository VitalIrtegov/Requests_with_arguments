#include <iostream>
#include <cpr/cpr.h>
#include <map>

int main() {
    std::cout << "Requests_with_arguments" << std::endl;

    std::string key, value;
    std::map<std::string, std::string> arguments;

    while (true) {
        std::cout << "Enter key: ";
        std::cin >> key;

        if (key == "get" || key == "post") break;

        std::cout << "Enter value: ";
        std::cin >> value;

        arguments.insert(std::make_pair(key, value));
    }

    if (key == "get") {
        std::string respons = "?";

        std::map<std::string, std::string>::const_iterator it = arguments.begin();
        for (auto it : arguments) {
            respons += it.first + "=" + it.second + "&";
        }
        respons.erase(std::prev(respons.end()));
        //std::cout << respons << std::endl;
        cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get" + respons));
        std::cout << r.text << std::endl;
    } else if (key == "post") {

    }

    return 0;
}
