//
// Created by pzz on 2021/12/21.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int result = 0;
        vector<int> candy(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        for (auto i: candy) {
            result += i;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> ratings{1, 0, 2};
    cout << solution.candy(ratings);
    return 0;
}