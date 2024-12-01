#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>   
#include <stdlib.h>
#include <map>

int main() {
    std::vector<int> left;
    std::map<int, int > map_right;
    int a, b;
    while (std::cin >> a >> b) {
        left.push_back(a);
        map_right[b]++;
    }
    int sum = 0;
    for (auto const& key : left) {
        if (map_right.find(key) != map_right.end()) {
            sum += key * map_right[key];
        } 
    }
    std::cout << sum << std::endl;
    return 0;
}

