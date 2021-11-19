//
// Created by pzz on 2021/11/19.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

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
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.size() == 0)
            return nullptr;

        //Find max number
        int splitIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[splitIndex]) {
                splitIndex = i;
            }
        }

        TreeNode *rootNode = new TreeNode(nums[splitIndex]);

        //Split vector
        vector<int> left(nums.begin(), nums.begin() + splitIndex);
        vector<int> right(nums.begin() + splitIndex + 1, nums.end());

        rootNode->left = constructMaximumBinaryTree(left);
        rootNode->right = constructMaximumBinaryTree(right);

        return rootNode;
    }
};

int main() {
    return 0;
}