//
// Created by pzz on 2021/12/30.
//

#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


using namespace std;

class Solution {
private:
    int result = 0;

    int traversal(TreeNode *root) {
        if (root == nullptr) {
            return 2;
        }

        int left = traversal(root->left);
        int right = traversal(root->right);

        if (left == 2 && right == 2)
            return 0;

        if (left == 0 || right == 0) {
            result++;
            return 1;
        }

        if (left == 1 || right == 1)
            return 2;

        return -1;
    }

public:
    int minCameraCover(TreeNode *root) {
        result = 0;

        if (traversal(root) == 0) {
            result++;
        }
        return result;
    }
};

int main() {
    return 0;
}