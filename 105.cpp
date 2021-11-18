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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0)
            return nullptr;

        int rootVal = preorder.front();
        TreeNode *root = new TreeNode(rootVal);

        int spiltIndex;
        for (spiltIndex = 0; spiltIndex < inorder.size(); spiltIndex++) {
            if (inorder[spiltIndex] == rootVal)
                break;
        }

        //spilt inorder
        vector<int> leftInorder(inorder.begin(), inorder.begin() + spiltIndex);
        vector<int> rightInorder(inorder.begin() + spiltIndex + 1, inorder.end());

        //spilt preorder
        preorder.erase(preorder.begin());
        vector<int> leftPreorder(preorder.begin(), preorder.begin() + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + leftInorder.size(), preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};

class Solution2 {
private:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preorderBegin, int preorderEnd, int inorderBegin,
                    int inorderEnd) {
        if (preorderBegin > preorderEnd) {
            return nullptr;
        }

        int rootVal = preorder[preorderBegin];
        TreeNode *root = new TreeNode(rootVal);

        if (preorderBegin == preorderEnd)
            return root;

        int splitIndex;
        for (splitIndex = inorderBegin; splitIndex <= inorderEnd; splitIndex++) {
            if (inorder[splitIndex] == rootVal)
                break;
        }

        //split inorder
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = splitIndex - 1;
        int rightInorderBegin = splitIndex + 1;
        int rightInorderEnd = inorderEnd;

        //split preorder
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = leftPreorderBegin + (leftInorderEnd - leftInorderBegin);

        int rightPreorderBegin = leftPreorderEnd + 1;
        int rightPreorderEnd = preorderEnd;

        root->left = build(preorder, inorder, leftPreorderBegin, leftPreorderEnd, leftInorderBegin, leftInorderEnd);
        root->right = build(preorder, inorder, rightPreorderBegin, rightPreorderEnd, rightInorderBegin, rightInorderEnd);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0)
            return nullptr;

        int preorderBegin = 0, preorderEnd = preorder.size() - 1;
        int inorderBegin = 0, inorderEnd = inorder.size() - 1;

        return build(preorder, inorder, preorderBegin, preorderEnd, inorderBegin, inorderEnd);
    }
};

int main() {
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    Solution2 solution2;
    solution2.buildTree(preorder, inorder);
    return 0;
}