//
// Created by pzz on 2021/11/20.
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
    void inorderTraversal(TreeNode *root, vector<int> &result) {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stack;
        TreeNode *cur = root;

        while (cur != nullptr || !stack.empty()) {
            if (cur != nullptr) {
                stack.push(cur);
                cur = cur->left;
            } else {
                cur = stack.top();
                stack.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
    }

public:
    int getMinimumDifference(TreeNode *root) {
        vector<int> result;
        inorderTraversal(root, result);

        if (result.size() < 2)
            return 0;
        
        int minValue = INT_MAX;

        for (int i = 1; i < result.size(); i++) {
            minValue = min(minValue, result[i] - result[i - 1]);
        }

        return minValue;
    }
};

int main() {
    return 0;
}