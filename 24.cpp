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
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *vHead = new ListNode(0, head);
        ListNode *pre = vHead, *cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            ListNode *temp = cur->next;
            pre->next = temp;
            cur->next = temp->next;
            temp->next = cur;
            pre = cur;
            cur = cur->next;
        }
        return vHead->next;
    }
};

int main() {
    ListNode *n3 = new ListNode(3);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);

    Solution solution;
    ListNode *head = solution.swapPairs(n1);

    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}