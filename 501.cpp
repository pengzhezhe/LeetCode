//
// Created by pzz on 2021/11/21.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
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
    unordered_map<int, int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> stack;
        unordered_map<int, int> result;

        if (root == nullptr)
            return result;

        TreeNode *cur = root;

        while (cur != nullptr || !stack.empty()) {
            if (cur != nullptr) {
                stack.push(cur);
                cur = cur->left;
            } else {
                cur = stack.top();
                result[cur->val]++;
                stack.pop();
                cur = cur->right;
            }
        }
        return result;
    }

    bool static compare(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }

public:
    vector<int> findMode(TreeNode *root) {
        unordered_map<int, int> map = inorderTraversal(root);
        vector<int> result;
        vector<pair<int, int>> res(map.begin(), map.end());
        sort(res.begin(), res.end(), compare);

        result.push_back(res[0].first);
        for (int i = 1; i < res.size(); i++) {
            if (res[i].second == res[0].second)
                result.push_back(res[i].first);
            else
                break;
        }

        return result;
    }
};


int main() {
    return 0;
}