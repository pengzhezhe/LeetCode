//
// Created by pzz on 2021/11/10.
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
    int minDepth(TreeNode *root) {
        int result = 0;
        queue<TreeNode *> queue;

        if (root == nullptr)
            return result;

        queue.push(root);
        while (!queue.empty()) {
            result++;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = queue.front();
                queue.pop();

                if (node->left == nullptr && node->right == nullptr) {
                    return result;
                }
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }
        return result;
    }
};

class Solution2 {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        if (root->left == nullptr && root->right != nullptr)
            return rightDepth + 1;
        if (root->left != nullptr && root->right == nullptr)
            return leftDepth + 1;

        return min(leftDepth, rightDepth) + 1;
    }
};

int main() {
    return 0;
}