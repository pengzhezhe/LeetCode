//
// Created by pzz on 2021/11/16.
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
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);

        int mid = 0;
        if (root->left && !root->left->left && !root->left->right) {
            mid = root->left->val;
        }
        return left + right + mid;
    }
};

int main() {
    return 0;
}