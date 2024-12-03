#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string corruptedMemory;
    std::getline(std::cin, corruptedMemory, '\0');

    std::regex mulPattern(R"(mul\((\d+),(\d+)\))");
    std::regex doPattern(R"(do\(\))");
    std::regex dontPattern(R"(don't\(\))");

    std::sregex_iterator it(corruptedMemory.begin(), corruptedMemory.end(), mulPattern);
    std::sregex_iterator it_end;

    bool doFound = true;
    int sum = 0;
    int lastMatchPos = 0;
    bool updateLastMatchPos = false;
    for (; it != it_end; ++it) {
        auto pos = it->position();
        std::string beforeMatch = corruptedMemory.substr(lastMatchPos, pos-lastMatchPos);
        if (std::regex_search(beforeMatch, dontPattern)) {
            doFound = false;
            updateLastMatchPos = true;
        } else if (std::regex_search(beforeMatch, doPattern)) {
            doFound = true;
            updateLastMatchPos = true;
        } else{
            updateLastMatchPos = false;
        }
        if (doFound) {
            int x = std::stoi(it->str(1));
            int y = std::stoi(it->str(2));
            sum += x * y;
        }
        if(updateLastMatchPos){
        lastMatchPos = pos + it->length();
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
