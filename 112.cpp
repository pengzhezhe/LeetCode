//
// Created by pzz on 2021/11/18.
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
private:
    int targetSum;

    bool traversal(TreeNode *root, int sum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum)
                return true;
            else
                return false;
        }

        if (root->left) {
            sum += root->left->val;
            if (traversal(root->left, sum))
                return true;
            sum -= root->left->val;
        }

        if (root->right) {
            sum += root->right->val;
            if (traversal(root->right, sum))
                return true;
            sum -= root->right->val;
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return false;

        this->targetSum = targetSum;
        int sum = root->val;

        return traversal(root, sum);
    }
};

int main() {
    return 0;
}