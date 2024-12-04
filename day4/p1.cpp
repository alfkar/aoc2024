#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>   
#include <stdlib.h>
#include <sstream>
#include <regex>

int foundXmas (std::vector<std::string> * lines, int x, int y, int i, int j) {
    std::string buff = "";
    std::string XMAS = "XMAS";
    int startindex = 0;
    for (int k = 0; k < 4; k++) {
        if (x >= 0 && x < lines->size() && y >= 0 && y < lines->at(x).size()) {
            buff+=lines->at(x)[y];
        }
        x = x + i;
        y = y + j;
    }
    if(buff == XMAS) {
        return 1;
    }
    return 0;
}

int tryAllXmas(std::vector<std::string> *lines, int x, int y) {
    // Check all 8 directions
    return foundXmas(lines, x, y, 0, 1)   + // Right
           foundXmas(lines, x, y, 0, -1)  + // Left
           foundXmas(lines, x, y, 1, 0)   + // Down
           foundXmas(lines, x, y, -1, 0)  + // Up
           foundXmas(lines, x, y, 1, 1)   + // Diagonal Down-Right
           foundXmas(lines, x, y, 1, -1)  + // Diagonal Down-Left
           foundXmas(lines, x, y, -1, 1)  + // Diagonal Up-Right
           foundXmas(lines, x, y, -1, -1);   // Diagonal Up-Left
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
            int nFound = tryAllXmas(&lines, x, y);  
                if (nFound > 0) {
                sum+=nFound;
            }
        }
    }
    
    std::cout << sum << std::endl;
    return 0;
}

