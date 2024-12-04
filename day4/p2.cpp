#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>   
#include <stdlib.h>
#include <sstream>
#include <regex>

bool isValidIndex(std::vector<std::string> *lines, int x, int y){
    if (x >= 0 && x < lines->size() && y >= 0 && y < lines->at(x).size()) {
        return true;
    }
    return false;
}

int foundXmas (std::vector<std::string> * lines, int x, int y) {
    std::string buff = "";
    std::string buff1 = "";
    if(lines->at(x)[y] != 'A'){
        return 0;
    }
     if(isValidIndex(lines, x+1,y+1) && isValidIndex(lines, x-1, y+1)  && isValidIndex(lines, x+1, y-1)  && isValidIndex(lines, x-1, y-1)){
            buff+=lines->at(x+1)[y+1];
            buff+=lines->at(x)[y];
            buff+=lines->at(x-1)[y-1];
            buff1+=lines->at(x+1)[y-1];
            buff1+=lines->at(x)[y];
            buff1+=lines->at(x-1)[y+1];
     }

    if((buff == "MAS" || buff == "SAM") && (buff1 == "MAS" || buff1 == "SAM")) {
        return 1;
    }
    return 0;
}

int main() {
    std::vector<std::string> lines;
    std::string line;

    // Read lines from standard input until EOF
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }
     int sum = 0;
     
    for (size_t x = 0; x < lines.size(); ++x) {  // x represents the row index
        for (size_t y = 0; y < lines[x].size(); ++y) {  // y represents the column index
                if (foundXmas(&lines, x, y) > 0) {
                    sum+=1;
            }
        }
    }
    
    std::cout << sum << std::endl;
    return 0;
}

