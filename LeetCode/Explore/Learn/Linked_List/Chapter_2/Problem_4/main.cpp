#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 自力AC,Time:O(n),Space:O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL && headB==NULL) return NULL;
        int n = 0, m = 0;
        auto p = headA, q = headB;
        while (p != NULL) { ++n; p = p->next; }
        while (q != NULL) { ++m; q = q->next; }
        p = headA; q = headB;
        if (n > m) while (n-m > 0) { p = p->next; --n; }
        else if (m > n) while (m-n > 0) { q = q->next; --m; }
        while (p!=NULL && q!=NULL && p!=q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
