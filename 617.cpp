//
// Created by pzz on 2021/11/19.
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};


class Solution2 {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        queue<TreeNode *> queue;
        queue.push(root1);
        queue.push(root2);

        while (!queue.empty()) {
            TreeNode *node1 = queue.front();
            queue.pop();
            TreeNode *node2 = queue.front();
            queue.pop();

            node1->val += node2->val;

            if (node1->left != nullptr && node2->left != nullptr) {
                queue.push(node1->left);
                queue.push(node2->left);
            }

            if (node1->right != nullptr && node2->right != nullptr) {
                queue.push(node1->right);
                queue.push(node2->right);
            }

            if (node1->left == nullptr && node2->left != nullptr) {
                node1->left = node2->left;
            }

            if (node1->right == nullptr && node2->right != nullptr) {
                node1->right = node2->right;
            }
        }
        return root1;
    }
};

int main() {
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* tree2;

    return 0;
}