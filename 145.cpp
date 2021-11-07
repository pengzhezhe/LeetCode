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
//    vector<int> postorderTraversal(TreeNode *root) {
//        vector<int> result;
//        postOrderTraversal(root, result);
//        return result;
//    }
//
//    void postOrderTraversal(TreeNode *root, vector<int> &result) {
//        if (root == nullptr)
//            return;
//        postOrderTraversal(root->left, result);
//        postOrderTraversal(root->right, result);
//        result.push_back(root->val);
//    }
//};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> stack;
        vector<int> result;

        if (root == nullptr)
            return result;

        stack.push(root);

        while (!stack.empty()) {
            TreeNode *node = stack.top();
            result.push_back(node->val);
            stack.pop();

            if (node->left != nullptr) {
                stack.push(node->left);
            }

            if (node->right != nullptr) {
                stack.push(node->right);
            }
        }

        reverse(result.begin(), result.end());
        
        return result;
    }
};

int main() {
    return 0;
}