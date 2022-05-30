//
// Created by pzz on 2022/5/30.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution2 {
public:
    vector<int> nums;
    int ans = 0;

    int sumRootToLeaf(TreeNode *root) {
        backtrace(root);
        return ans;
    }

    void backtrace(TreeNode *root) {
        nums.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            int n = nums.size();
            int temp = 1;
            for (int i = n - 1; i >= 0; i--) {
                ans += nums[i] * temp;
                temp *= 2;
            }
            return;
        }
        if (root->left) {
            backtrace(root->left);
            nums.pop_back();
        }
        if (root->right) {
            backtrace(root->right);
            nums.pop_back();
        }
    }
};

class Solution {
public:
    int sumRootToLeaf(TreeNode *root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode *root, int val) {
        if (root == nullptr) {
            return 0;
        }

        val = (val << 1) | root->val;

        if (root->left == nullptr && root->right == nullptr)
            return val;

        return dfs(root->left, val) + dfs(root->right, val);
    }
};

int main() {
    return 0;
}