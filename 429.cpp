//
// Created by pzz on 2021/11/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result;
        queue<Node *> queue;
        if (root == nullptr)
            return result;
        queue.push(root);

        while (!queue.empty()) {
            int size = queue.size();
            vector<int> vector;
            for (int i = 0; i < size; ++i) {
                Node *node = queue.front();
                queue.pop();
                vector.push_back(node->val);

                for (auto c: node->children) {
                    if (c != nullptr)
                        queue.push(c);
                }
            }
            result.push_back(vector);
        }
        return result;
    }
};

int main() {
    return 0;
}