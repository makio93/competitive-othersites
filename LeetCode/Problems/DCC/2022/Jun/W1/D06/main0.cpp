// 自力AC

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
        int n = 0, m = 0;
        while (p != NULL) {
            p = p->next;
            ++n;
        }
        while (q != NULL) {
            q = q->next;
            ++m;
        }
        p = headA; q = headB;
        if (n >= m) for (int i=0; i<n-m; ++i) p = p->next;
        else for (int i=0; i<m-n; ++i) q = q->next;
        while (p != NULL) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
