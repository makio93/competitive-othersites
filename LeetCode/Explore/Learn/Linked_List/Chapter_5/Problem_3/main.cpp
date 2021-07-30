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

// 自力AC

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        auto p = l1;
        while (p != nullptr) {
            ++len1;
            p = p->next;
        }
        p = l2;
        while (p != nullptr) {
            ++len2;
            p = p->next;
        }
        ListNode *res = new ListNode(0);
        int cnt = 0, mval = max(len1, len2);
        p = res;
        while (cnt < mval) {
            if (cnt < len1) { p->val += l1->val; l1 = l1->next; }
            if (cnt < len2) { p->val += l2->val; l2 = l2->next; }
            int r = p->val / 10;
            p->val %= 10;
            if (cnt+1<mval || r>0) { p->next = new ListNode(r); p = p->next; }
            ++cnt;
        }
        return res;
    }
};
