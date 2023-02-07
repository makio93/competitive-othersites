// 解説AC2,ポインタのポインタ変数

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head, *p = head, *q = (p == nullptr) ? p : p->next;
        while (p!=nullptr && q!=nullptr) {
            p->next = q->next;
            q->next = p;
            *pp = q;
            pp = &(p->next);
            p = *pp, q = (p == nullptr) ? p : p->next;
        }
        return head;
    }
};
