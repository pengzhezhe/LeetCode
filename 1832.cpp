//
// Created by pzz on 2022/5/30.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int map[26] = {0};
        for (auto c: sentence)
            map[c - 'a']++;

        for (int n: map)
            if (n < 1)
                return false;
        return true;
    }
};

class Solution2 {
public:
    bool checkIfPangram(string sentence) {
        int bits = 0;
        for (char c: sentence) {
            bits |= 1 << (c - 'a');
        }
        return bits == (1 << 26) - 1;
    }
};

int main() {
    return 0;
}