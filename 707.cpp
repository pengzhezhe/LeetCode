//
// Created by pzz on 2021/10/12.
//

#include <iostream>
#include <algorithm>

using namespace std;

class MyLinkedList {
public:
    struct LinkedNode {
        int val;

        LinkedNode *next;

        LinkedNode(int val) : val(val), next(nullptr) {}

        LinkedNode(int val, LinkedNode *next) : val(val), next(next) {}
    };

    MyLinkedList() {
        size = 0;
        pre = new LinkedNode(0);
    }

    int get(int index) {
        if (index < 0 || index > size)
            return -1;
        int i = 0;
        LinkedNode *p = pre;
        while (p->next != nullptr) {
            if (index == i)
                return p->next->val;
            p = p->next;
            i++;
        }
        return -1;
    }

    void addAtHead(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *temp = pre->next;
        pre->next = newNode;
        newNode->next = temp;
        size++;
    }

    void addAtTail(int val) {
        LinkedNode *p = pre;
        while (p->next != nullptr)
            p = p->next;
        LinkedNode *newNode = new LinkedNode(val);
        p->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index <= 0)
            return addAtHead(val);
        if (index > size)
            return;
        if (index == size)
            return addAtTail(val);
        int i = 0;
        LinkedNode *p = pre;
        while (p->next != nullptr) {
            if (index == i) {
                LinkedNode *newNode = new LinkedNode(val);
                LinkedNode *temp = p->next;
                p->next = newNode;
                newNode->next = temp;
                size++;
                break;
            }
            p = p->next;
            i++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > size)
            return;
        int i = 0;
        LinkedNode *p = pre;
        while (p->next != nullptr) {
            if (index == i) {
                LinkedNode *temp = p->next;
                p->next = temp->next;
                delete temp;
                size--;
                break;
            }
            p = p->next;
            i++;
        }
    }

private:
    int size;
    LinkedNode *pre;
};

int main() {

}
