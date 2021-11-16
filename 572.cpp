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
private:
    bool compare(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr && q != nullptr)
            return false;
        if (p != nullptr && q == nullptr)
            return false;
        if (p->val != q->val)
            return false;

        return compare(p->left, q->left) && compare(p->right, q->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr)
            return false;

        if (compare(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    return 0;
}