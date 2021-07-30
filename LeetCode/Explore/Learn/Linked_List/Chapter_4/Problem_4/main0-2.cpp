#include <bits/stdc++.h>
using namespace std;

// 自力AC2(双方向リスト)

class MyLinkedList {
    struct Node {
        int val;
        Node *next, *prev;
        Node(int val=0, Node* next=NULL, Node* prev=NULL) : val(val), next(next), prev(prev) {}
    };
    Node *head, *tail;
    int len;
public:
    MyLinkedList() {
        head = tail = NULL;
        len = 0;
    }
    int get(int index) {
        if (index >= len) return -1;
        if (index <= len-index-1) {
            int cnt = 0;
            auto p = head;
            while (cnt != index) {
                p = p->next;
                ++cnt;
            }
            return p->val;
        }
        else {
            int cnt = len-1;
            auto p = tail;
            while (cnt != index) {
                p = p->prev;
                --cnt;
            }
            return p->val;
        }
    }
    void addAtHead(int val) {
        head = new Node(val, head);
        if (len == 0) tail = head;
        else head->next->prev = head;
        ++len;
    }
    void addAtTail(int val) {
        if (len == 0) head = tail = new Node(val);
        else {
            tail = new Node(val, NULL, tail);
            tail->prev->next = tail;
        }
        ++len;
    }
    void addAtIndex(int index, int val) {
        if (index > len) return;
        if (index == 0) addAtHead(val);
        else if (index == len) addAtTail(val);
        else {
            int cnt = 0;
            auto p = head;
            if (index <= len-index-1) {
                while (cnt != index) {
                    p = p->next;
                    ++cnt;
                }
            }
            else {
                cnt = len-1;
                p = tail;
                while (cnt != index) {
                    p = p->prev;
                    --cnt;
                }
            }
            p->prev = p->prev->next = new Node(val, p, p->prev);
            ++len;
        }
    }
    void deleteAtIndex(int index) {
        if (index >= len) return;
        if (len == 1) {
            head = head->next;
            tail = head;
        }
        else {
            int cnt = 0;
            auto p = head;
            if (index <= len-index-1) {
                while (cnt != index) {
                    p = p->next;
                    ++cnt;
                }
            }
            else {
                cnt = len - 1;
                p = tail;
                while (cnt != index) {
                    p = p->prev;
                    --cnt;
                }
            }
            if (p->prev != NULL) p->prev->next = p->next;
            if (p->next != NULL) p->next->prev = p->prev;
            if (index == 0) head = head->next;
            else if (index == len-1) tail = tail->prev;
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
