//
// Created by pzz on 2021/10/16.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *slow = dummyNode, *fast = dummyNode;
        while (n--)
            fast = fast->next;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return dummyNode->next;
    }
};

int main() {
    ListNode *n3 = new ListNode(3);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);

    Solution solution;
    ListNode *head = solution.removeNthFromEnd(n1, 3);

    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}