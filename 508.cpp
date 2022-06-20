//
// Created by pzz on 2022/6/19.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> umap;
    int maxCount = 0;

public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        traversal(root);
        vector<int> ans;

        for (auto &p: umap) {
            if (p.second == maxCount)
                ans.emplace_back(p.first);
        }

        return ans;
    }

    int traversal(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int sum = traversal(root->left) + traversal(root->right) + root->val;

        maxCount = max(maxCount, ++umap[sum]);
        return sum;
    }
};