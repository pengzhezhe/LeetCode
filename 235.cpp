//
// Created by pzz on 2021/11/22.
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);

        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr)
            return root;

        if (left != nullptr && right == nullptr)
            return left;

        if (left == nullptr && right != nullptr)
            return right;

        return nullptr;
    }
};

class Solution2 {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return root;


        if (root->val > p->val && root->val > q->val) {
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            if (left != nullptr)
                return left;
        }

        if (root->val < p->val && root->val < q->val) {
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            if (right != nullptr)
                return right;
        }

        return root;
    }
};

int main() {
    return 0;
}