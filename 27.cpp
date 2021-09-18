#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                n--;
                i--;
            }
        }
        return n;
    }
};


int main() {
    vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    Solution s;
    int n = s.removeElement(nums, val);
    cout << n << endl;
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }
    return 0;
}