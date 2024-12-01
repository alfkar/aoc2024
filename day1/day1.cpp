#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>   
#include <stdlib.h>

int main() {
    std::vector<int> vector1;
    std::vector<int> vector2;

    int a, b;
    while (std::cin >> a >> b) {
        vector1.push_back(a);
        vector2.push_back(b);
    }
    std::sort (vector1.begin(), vector1.end());
    std::sort (vector2.begin(), vector2.end());
    int sum = 0;
    for(int i = 0; i < vector1.size(); i++) {
        sum += abs(vector1[i] - vector2[i]);
    }
    std::cout << sum << std::endl;
    return 0;
}

