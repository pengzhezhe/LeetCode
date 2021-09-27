//
// Created by pzz on 2021/9/27.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int> &fruits) {
        int ans = 0;
        unordered_map<int, int> buckets;
        int i = 0;
        for (int j = 0; j < fruits.size(); j++) {
            buckets[fruits[j]]++;
            while (buckets.size() > 2) {
                buckets[fruits[i]]--;
                if (buckets[fruits[i]] == 0)
                    buckets.erase(fruits[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main() {
    vector<int> fruits{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    Solution solution;
    cout << solution.totalFruit(fruits);
    return 0;
}