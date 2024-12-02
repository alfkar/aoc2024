#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>   
#include <stdlib.h>
#include <sstream>


int main() {
    std::vector<std::vector<int>> matrix;
    std::string line;
    // Read input line by line
    while (std::getline(std::cin, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        int value;
        while (iss >> value) {
            row.push_back(value);
        }
        if (!row.empty()) {
            matrix.push_back(row);
        }
    }
    int safeCounter = 0;        
    for (const auto& row : matrix) {
        bool incOrDec = (row[0] - row [1]) > 0; 
        bool safe = true;
        for (int i = 1; i < row.size(); i++) {
          int iod = row[i-1] - row[i];
          if((iod > 0) != incOrDec || iod == 0 || abs(iod) > 3){
            safe = false;
            i++;
            break; 
          }
        }
        if(safe){
          safeCounter++;
        }
    }
    std::cout << safeCounter << "\n";
    return 0;
}

