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
private:
    int target;

    void traversal(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &result) {
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == target) {
                result.push_back(path);
            }
            return;
        }

        if (root->left) {
            sum += root->left->val;
            path.push_back(root->left->val);
            traversal(root->left, sum, path, result);
            sum -= root->left->val;
            path.pop_back();
        }

        if (root->right) {
            sum += root->right->val;
            path.push_back((root->right->val));
            traversal(root->right, sum, path, result);
            sum -= root->right->val;
            path.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;

        int sum = 0;
        this->target = targetSum;
        vector<int> path;

        sum += root->val;
        path.push_back(root->val);

        traversal(root, sum, path, result);
        return result;
    }
};

int main() {
    return 0;
}