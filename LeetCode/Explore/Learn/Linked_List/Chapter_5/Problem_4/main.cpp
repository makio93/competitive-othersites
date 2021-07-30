#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// 自力AC

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        auto res = head, p = head;
        while (p != nullptr) {
            if (p->child == nullptr) p = p->next;
            else {
                auto pl = flatten(p->child), pr = pl;
                while (pr->next != nullptr) pr = pr->next;
                pl->prev = p; pr->next = p->next; p->next = pl;
                if (pr->next != nullptr) pr->next->prev = pr;
                p->child = nullptr;
                p = pr->next;
            }
        }
        return res;
    }
};
