//
// Created by pzz on 2022/3/10.
//

#include <iostream>
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
public:
    int rob(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int money1 = root->val;

        if (root->left)
            money1 += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            money1 += rob(root->right->left) + rob(root->right->right);

        int money2 = rob(root->left) + rob(root->right);

        return max(money1, money2);
    }
};

class Solution2 {
public:

    vector<int> robTree(TreeNode *root) {
        if (root == nullptr)
            return vector<int>{0, 0};

        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);

        //偷当前节点
        int money1 = root->val + left[0] + right[0];
        //不偷
        int money2 = max(left[0], left[1]) + max(right[0], right[1]);

        return vector<int>{money2, money1};
    }

    int rob(TreeNode *root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
};