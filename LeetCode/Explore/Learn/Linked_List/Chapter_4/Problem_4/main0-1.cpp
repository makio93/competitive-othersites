#include <bits/stdc++.h>
using namespace std;

// 自力AC1(単方向リスト)

class MyLinkedList {
    struct Node {
        int val;
        Node *next;
        Node(int val=0, Node* next=NULL) : val(val), next(next) {}
    };
    Node *head, *tail;
    int len;
public:
    MyLinkedList() {
        head = tail = NULL;
        len = 0;
    }
    int get(int index) {
        if (index < len) {
            int cnt = 0;
            auto p = head;
            while (cnt < index) {
                p = p->next;
                ++cnt;
            }
            return p->val;
        }
        else return -1;
    }
    void addAtHead(int val) {
        head = new Node(val, head);
        if (len == 0) tail = head;
        ++len;
    }
    void addAtTail(int val) {
        if (len == 0) head = tail = new Node(val);
        else {
            tail->next = new Node(val);
            tail = tail->next;
        }
        ++len;
    }
    void addAtIndex(int index, int val) {
        if (index == 0) addAtHead(val);
        else if (index == len) addAtTail(val);
        else if (index>0 && index<len) {
            int cnt = 0;
            auto p = head;
            while (cnt+1 < index) {
                p = p->next;
                ++cnt;
            }
            p->next = new Node(val, p->next);
            ++len;
        }
    }
    void deleteAtIndex(int index) {
        if (index >= len) return;
        if (index == 0) {
            head = head->next;
            if (len == 1) tail = head;
        }
        else {
            int cnt = 0;
            auto p = head;
            while (cnt+1 < index) {
                p = p->next;
                ++cnt;
            }
            p->next = p->next->next;
            if (index == len-1) tail = p;
        }
        --len;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
