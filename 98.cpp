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
    void inorderTraver(TreeNode *root, vector<int> &result) {
        if (root == nullptr)
            return;
        inorderTraver(root->left, result);
        result.push_back(root->val);
        inorderTraver(root->right, result);
    }

    vector<int> inorderTraver(TreeNode *root) {
        stack<TreeNode *> stack;
        vector<int> result;

        if (root == nullptr)
            return result;

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
    bool isValidBST(TreeNode *root) {
        vector<int> result;

        inorderTraver(root, result);

        if (result.empty())
            return false;

        if (result.size() == 1) {
            return true;
        }

        for (int i = 1; i < result.size(); i++) {
            if (result[i] <= result[i - 1]) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    return 0;
}