// 解説AC

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p = headA, q = headB;
        while (p != q) {
            p = p->next;
            q = q->next;
            if (p == q) return p;
            if (p == NULL) p = headB;
            if (q == NULL) q = headA;
        }
        return p;
    }
};
