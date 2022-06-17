//
// Created by pzz on 2022/6/17.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int> &arr) {
        int n = arr.size();

        int i = 0, j = n - 1, k = n - 1;

        while (i <= j) {
            if (arr[i] == 0) {
                if (i == j) {
                    arr[k--] = 0;
                    j--;
                    break;
                }
                j--;
            }
            i++;
        }

        while (k >= 0) {
            if (arr[j] == 0) {
                arr[k] = 0;
                k--;
            }
            arr[k] = arr[j];
            k--;
            j--;
        }
    }
};

int main() {
    vector<int> arr{0, 0, 0, 0, 0, 0, 0};
    Solution solution = Solution();

    solution.duplicateZeros(arr);

    for (int i: arr)
        cout << i << endl;
    return 0;
}