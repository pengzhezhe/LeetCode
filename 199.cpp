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
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> queue;
        vector<int> result;

        if (root == nullptr)
            return result;

        queue.push(root);

        while (!queue.empty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                if (i == size - 1) {
                    result.push_back(node->val);
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

int main() {
    return 0;
}