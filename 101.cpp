//
// Created by pzz on 2021/11/13.
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
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        return compare(root->left, root->right);
    }

    bool compare(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr)
            return true;
        else if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left->val != right->val)
            return false;
        else {
            return compare(left->left, right->right) && compare(left->right, right->left);
        }
    }
};


class Solution2 {
public:
    bool isSymmetric(TreeNode *root) {
        queue<TreeNode *> queue;
        if (root == nullptr)
            return true;

        queue.push(root->left);
        queue.push(root->right);

        while (!queue.empty()) {
            TreeNode *leftNode = queue.front();
            queue.pop();
            TreeNode *rightNode = queue.front();
            queue.pop();

            if (leftNode == nullptr && rightNode == nullptr)
                continue;

            if ((leftNode == nullptr || rightNode == nullptr) || (leftNode->val != rightNode->val))
                return false;
            queue.push(leftNode->left);
            queue.push(rightNode->right);
            queue.push(leftNode->right);
            queue.push(rightNode->left);
        }
        return true;
    }
};

int main() {
    return 0;
}