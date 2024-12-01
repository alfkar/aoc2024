#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>   
#include <stdlib.h>
#include <map>

int main() {
    std::vector<int> vector1;
    std::map<int, int > map2;
    int a, b;
    while (std::cin >> a >> b) {
        vector1.push_back(a);
        map2[b]++;
    }
    int sum = 0;
    for (auto const& key : vector1) {
        if (map2.find(key) != map2.end()) {
            sum += key * map2[key];
        } 
    }
    std::cout << sum << std::endl;
    return 0;
}

