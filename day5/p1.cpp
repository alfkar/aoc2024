#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

bool containsAll(std::vector<int> row, std::map<int, std::map<int, int>> rules) {
    for (int i = 0; i < row.size(); i++) {
        int currentVal = row.at(i);
        for (size_t k = i + 1; k < row.size(); k++) {
            if(rules[currentVal].count(row.at(k))>0) {
                continue;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

std::vector<int> reOrder(std::vector<int> row, std::map<int, std::map<int, int>> rules){
    for (int i = 0; i < row.size(); i++) {
        int currentVal = row.at(i);
        for (size_t k = i + 1; k < row.size(); k++) {
          if(rules[currentVal].count(row.at(k))>0) {
                continue;
            }
          else {
            std::swap(row[i], row[k]);
            i--;
            break;
          }
         for(const auto& val: row){
                std::cout << val << " ";
            }
        std::cout << std::endl;
           
        }
    }
    return row;

}

int main() {
    std::map<int, std::map<int, int>> rules;    // Map to store multiple values per key
    std::vector<std::vector<int>> matrix;     // To store the matrix
    std::string line;
    bool isReadingMap = true;                 // Toggle between reading map and matrix

    while (std::getline(std::cin, line)) {
        if (line.empty()) {                   // A blank line separates map and matrix
            isReadingMap = false;
            continue;
        }

        if (isReadingMap) {
            // Replace '|' with space for easier parsing
            std::replace(line.begin(), line.end(), '|', ' ');
            std::istringstream lineStream(line);
            int key, value;
            lineStream >> key >> value;
            rules[key][value] = 1;      
        } else {
            // Replace ',' with space for easier parsing
            std::replace(line.begin(), line.end(), ',', ' ');
            std::istringstream lineStream(line);
            std::vector<int> row;
            int value;
            while (lineStream >> value) {
                row.push_back(value);
            }
            matrix.push_back(row);
        }
    }


    int sum = 0;
    // Print the matrix to verify
    for (const auto& row : matrix) {
        if(!containsAll(row, rules)){
            std::vector<int> newRow = reOrder(row, rules);
            sum += newRow[ceil(newRow.size()/2)];
        }
    }
    std::cout << sum << std::endl;

    return 0;
}
