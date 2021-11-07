//
// Created by pzz on 2021/11/7.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode *root) {
//        vector<int> result;
//        inOrderTraversal(root, result);
//        return result;
//    }
//
//    void inOrderTraversal(TreeNode *root, vector<int> &result) {
//        if (root == nullptr)
//            return;
//        inOrderTraversal(root->left, result);
//        result.push_back(root->val);
//        inOrderTraversal(root->right, result);
//    }
//};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> stack;
        vector<int> result;
        TreeNode *cur = root;

        while (cur != nullptr || !stack.empty()) {
            if (cur != nullptr) {
                stack.push(cur);
                cur = cur->left;
            } else {
                cur = stack.top();
                result.push_back(cur->val);
                stack.pop();
                cur = cur->right;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}