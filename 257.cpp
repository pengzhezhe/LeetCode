//
// Created by pzz on 2021/11/16.
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
    void traversal(TreeNode *cur, vector<int> &path, vector<string> &result) {
        path.push_back(cur->val);

        if (cur->left == nullptr && cur->right == nullptr) {
            string pathS;
            for (auto node: path) {
                pathS += to_string(node);
                pathS += "->";
            }
            pathS = pathS.substr(0, pathS.size() - 2);
            result.push_back(pathS);
            return;
        }


        if (cur->left) {
            traversal(cur->left, path, result);
            path.pop_back();
        }

        if (cur->right) {
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<int> path;
        vector<string> result;

        if (root == nullptr)
            return result;

        traversal(root, path, result);
        return result;
    }
};

int main() {
    return 0;
}