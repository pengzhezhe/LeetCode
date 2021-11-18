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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0)
            return nullptr;

        int rootVal = postorder.back();
        TreeNode *root = new TreeNode(rootVal);

        int spiltIndex;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                spiltIndex = i;
                break;
            }
        }

        //spiltIndex inorder
        vector<int> leftInorder(inorder.begin(), inorder.begin() + spiltIndex);
        vector<int> rightInorder(inorder.begin() + spiltIndex + 1, inorder.end());

        //spiltIndex postorder
        postorder.pop_back();
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};

int main() {
    return 0;
}