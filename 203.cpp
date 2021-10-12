//
// Created by pzz on 2021/10/12.
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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode first = ListNode(0, head);
        ListNode *p = &first;

        while (p->next != nullptr) {
            if (p->next->val == val) {
                ListNode *tmp = p->next;
                p->next = tmp->next;
                delete tmp;
            } else {
                p = p->next;
            }
        }
        return first.next;
    }
};

int main() {

    int val = 6;
    ListNode node6 = ListNode(6, nullptr);
    ListNode node5 = ListNode(5, &node6);
    ListNode node4 = ListNode(4, &node5);
    ListNode node3 = ListNode(3, &node4);
    ListNode node2 = ListNode(2, &node3);
    ListNode node1 = ListNode(1, &node2);

    Solution solution;
    ListNode *head = solution.removeElements(&node1, val);
    ListNode *p = head;
    while (p != nullptr) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}