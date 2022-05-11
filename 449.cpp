//
// Created by pzz on 2022/5/11.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    void postOrder(TreeNode *root, vector<int> &ans) {
        if (root == nullptr)
            return;
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.emplace_back(root->val);
    }

    vector<int> split(string &str) {
        int n = (int) str.size();
        vector<int> nums;
        int start = 0;
        int pos = 0;
        while (pos < n) {
            while (pos < n && str[pos] == ',')
                pos++;
            start = pos;
            while (pos < n && str[pos] != ',')
                pos++;
            if (start < str.size()) {
                string s = str.substr(start, pos - start);
                nums.emplace_back(stoi(s));
            }
        }
        return nums;
    }

    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0)
            return nullptr;

        int rootVal = postorder.back();
        TreeNode *root = new TreeNode(rootVal);

        if (postorder.size() == 1)
            return root;

        int rootIndex = 0;
        for (; rootIndex < inorder.size(); rootIndex++) {
            if (inorder[rootIndex] == rootVal)
                break;
        }

        vector<int> leftInoder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());

        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInoder.size());
        vector<int> rightPostorder(postorder.begin() + leftInoder.size(), postorder.end());

        root->left = traversal(leftInoder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        vector<int> ans;
        postOrder(root, ans);
        string str;
        for (int i = 0; i < ans.size(); i++) {
            if (i != ans.size() - 1)
                str.append(to_string(ans[i]) + ',');
            else
                str.append(to_string(ans[i]));
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.size() == 0)
            return nullptr;

        vector<int> postorder = split(data);

        if (postorder.size() == 0)
            return nullptr;
        vector<int> inoder(postorder);
        sort(inoder.begin(), inoder.end());

        TreeNode *root = traversal(inoder, postorder);
        return root;
    }
};

int main() {
    Codec codec = Codec();
    TreeNode *root = new TreeNode(3);
    TreeNode *left = new TreeNode(1);
    TreeNode *right = new TreeNode(4);
    root->left = left;
    root->right = right;
    left->right = new TreeNode(2);
    string str = codec.serialize(root);
    TreeNode *tree = codec.deserialize(str);
    return 0;
}