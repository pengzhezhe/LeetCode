//
// Created by pzz on 2021/11/13.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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
    int maxDepth(Node *root) {
        if (root == nullptr)
            return 0;
        int depth = 0;
        for (auto node: root->children) {
            depth = max(depth, maxDepth(node));
        }
        return depth + 1;
    }
};

class Solution2 {
public:
    int maxDepth(Node *root) {
        queue<Node *> queue;
        int result = 0;

        if (root == nullptr)
            return result;

        queue.push(root);

        while (!queue.empty()) {
            result++;
            int size = queue.size();

            for (int i = 0; i < size; ++i) {
                Node *node = queue.front();
                queue.pop();

                for (auto n: node->children) {
                    if (n)
                        queue.push(n);
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}