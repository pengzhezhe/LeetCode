//
// Created by pzz on 2021/11/18.
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
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> queue;
        queue.push(root);
        int result = root->val;

        while (!queue.empty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front();
                queue.pop();

                if (i == 0)
                    result = node->val;

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
private:
    int maxDepth = INT_MIN;
    int maxLeftValue = INT_MIN;

    void traversal(TreeNode *root, int depth) {
        if (root->left == nullptr && root->right == nullptr) {
            if (depth > maxDepth) {
                maxDepth = depth;
                maxLeftValue = root->val;
            }
            return;
        }

        if (root->left) {
            depth++;
            traversal(root->left, depth);
            depth--;
        }

        if (root->right) {
            depth++;
            traversal(root->right, depth);
            depth--;
        }
    }

public:
    int findBottomLeftValue(TreeNode *root) {
        int depth = 0;
        traversal(root, depth);
        return maxLeftValue;
    }

};

int main() {
    return 0;
}