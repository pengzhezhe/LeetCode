//
// Created by pzz on 2021/11/29.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode *generateTree(vector<int> &nums, int start, int end) {
        if (start > end)
            return nullptr;

        int location = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[location]);

        root->left = generateTree(nums, start, location - 1);
        root->right = generateTree(nums, location + 1, end);

        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return generateTree(nums, 0, nums.size() - 1);
    }
};

int main() {
    return 0;
}