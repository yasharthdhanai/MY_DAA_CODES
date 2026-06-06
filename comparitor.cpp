#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareBySecondElement(const vector<int>& a, const vector<int>& b) {
    if(a[1] == b[1]){
        return a[0] < b[0]; // If second elements are equal, compare first elements
    }
    return a[1] < b[1];
}

int main() {
    vector<vector<int>> vec = { {1, 5}, {2, 1}, {3, 8}, {4, 3}};

    // Pass the function name as the third argument
    sort(vec.begin(), vec.end(), compareBySecondElement);

    for (const auto& row : vec) {
        std::cout << "[" << row[0] << ", " << row[1] << "] ";
    }

    return 0;
}