//
// Created by pzz on 2021/11/13.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

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
    int countNodes(TreeNode *root) {
        queue<TreeNode *> queue;
        int result = 0;

        if (root == nullptr)
            return result;

        queue.push(root);

        while (!queue.empty()) {
            int size = queue.size();
            result += size;
            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front();
                queue.pop();
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
    int countNodes(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int left = countNodes(root->left);
        int right = countNodes(root->right);

        return left + right + 1;
    }
};

class Solution3 {
public:
    int countNodes(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int leftHeight = 0, rightHeight = 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        while (left) {
            left = left->left;
            leftHeight++;
        }

        while (right) {
            right = right->right;
            rightHeight++;
        }

        if (leftHeight == rightHeight)
            return pow(2.0, leftHeight);

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main() {
    return 0;
}
