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
    TreeNode *invertTree(TreeNode *root) {
        queue<TreeNode *> queue;
        if (root == nullptr)
            return root;

        queue.push(root);

        while (!queue.empty()) {
            int size = queue.size();

            for (int i = 0; i < size; ++i) {
                TreeNode *node = queue.front();
                queue.pop();
                TreeNode *tmp = node->left;
                node->left = node->right;
                node->right = tmp;

                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }

        return root;
    }
};


int main() {

    return 0;
}