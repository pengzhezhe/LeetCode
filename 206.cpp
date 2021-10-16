//
// Created by pzz on 2021/10/15.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr, *p = head;
        while (p != nullptr) {
            ListNode *temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }
        return pre;
    }
};

int main() {
    ListNode n2 = ListNode(2);
    ListNode n1 = ListNode(1, &n2);

    Solution solution;
    ListNode *head = solution.reverseList(&n1);

    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}