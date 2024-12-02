#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>


bool isSafe(std::vector<int> row){
  bool safe = true;
  bool incOrDec = (row[1] - row[2] > 0);
  for(int i = 1; i < row.size(); i++){
    int iod = row[i-1] - row[i];
       if((iod > 0) != incOrDec || iod == 0 || abs(iod) > 3){
        return false;
       }
  }
  return true;
}

bool canBeMadeSafe(std::vector<int> row){
  for(int i = 0; i<row.size(); i++){
    std::vector<int> modifiedRow = row;
    modifiedRow.erase(modifiedRow.begin() + i);
      if(isSafe(modifiedRow)){
        return true;
      }
    }
  return false;
}
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
        if(canBeMadeSafe(row)||isSafe(row)){
          safeCounter++;
        }
    }
    std::cout << safeCounter << "\n";
    return 0;
}


