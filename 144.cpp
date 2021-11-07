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
//    vector<int> preorderTraversal(TreeNode *root) {
//        vector<int> result;
//        preOrderTraversal(root, result);
//        return result;
//    }
//
//    void preOrderTraversal(TreeNode *root, vector<int> &result) {
//        if (root == nullptr)
//            return;
//        result.push_back(root->val);
//        preOrderTraversal(root->left,result);
//        preOrderTraversal(root->right,result);
//    }
//};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> stack;
        vector<int> result;

        if (root == nullptr)
            return result;

        stack.push(root);

        while (!stack.empty()) {
            TreeNode *node = stack.top();
            result.push_back(node->val);
            stack.pop();

            //Note: push right first to make sure visiting left node first.
            if (node->right != nullptr) {
                stack.push(node->right);
            }

            if (node->left != nullptr) {
                stack.push(node->left);
            }
        }

        return result;
    }
};

int main() {
    return 0;
}