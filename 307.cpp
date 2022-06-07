//
// Created by pzz on 2022/6/6.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> segmentTree;
    int n;

    void buildTree(int node, int start, int end, vector<int> &nums) {
        if (start == end) {
            segmentTree[node] = nums[start];
            return;
        }
        int middle = start + (end - start) / 2;
        buildTree(node * 2 + 1, start, middle, nums);
        buildTree(node * 2 + 2, middle + 1, end, nums);
        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
    }

    void change(int index, int val, int node, int start, int end) {
        if (start == end) {
            segmentTree[node] = val;
            return;
        }

        int middle = start + (end - start) / 2;

        if (index <= middle) {
            change(index, val, node * 2 + 1, start, middle);
        } else {
            change(index, val, node * 2 + 2, middle + 1, end);
        }
        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
    }

    int range(int left, int right, int node, int start, int end) {
        if (left == start && right == end)
            return segmentTree[node];

        int middle = start + (end - start) / 2;

        if (right <= middle) {
            return range(left, right, node * 2 + 1, start, middle);
        } else if (left > middle) {
            return range(left, right, node * 2 + 2, middle + 1, end);
        } else {
            return range(left, middle, node * 2 + 1, start, middle) +
                   range(middle + 1, right, node * 2 + 2, middle + 1, end);
        }
    }

public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        segmentTree = vector<int>(4 * n);
        buildTree(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        change(index, val, 0, 0, n - 1);
    }

    int sumRange(int left, int right) {
        return range(left, right, 0, 0, n - 1);
    }
};

int main() {
    return 0;
}