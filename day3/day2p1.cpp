#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>   
#include <stdlib.h>
#include <sstream>
#include <regex>

int main() {
    std::string corruptedMemory;
    std::getline(std::cin, corruptedMemory, '\0');
 
    std::regex pattern(R"(mul\((\d+),(\d+)\))");

    std::sregex_iterator it(corruptedMemory.begin(), corruptedMemory.end(), pattern);
    std::sregex_iterator it_end;
    int sum = 0;
    for(; it != it_end; ++it) {
        int x = std::stoi(it->str(1));
        int y = std::stoi(it->str(2));
        sum += x * y;
    }
    std::cout << sum << std::endl;
    return 0;
}

