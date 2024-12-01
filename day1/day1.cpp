#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>   
#include <stdlib.h>

int main() {
    std::vector<int> left;
    std::vector<int> right;
    int a, b;
    while (std::cin >> a >> b) {
        left.push_back(a);
        right.push_back(b);
    }
    std::sort (left.begin(), left.end());
    std::sort (right.begin(), right.end());
    int sum = 0;
    for(int i = 0; i < left.size(); i++) {
        sum += abs(left[i] - right[i]);
    }
    std::cout << sum << std::endl;
    return 0;
}

