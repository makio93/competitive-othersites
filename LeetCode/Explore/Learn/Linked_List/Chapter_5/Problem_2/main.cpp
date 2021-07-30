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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==nullptr && l2==nullptr) return nullptr;
        ListNode *p = nullptr, *q = nullptr;
        if (l1 == nullptr) p = l2;
        else if (l2 == nullptr) p = l1;
        else if (l1->val <= l2->val) { p = l1; q = l2; }
        else { p = l2; q = l1; }
        ListNode *res = p;
        while (p != nullptr) {
            while (p!=nullptr && (q==nullptr || (p->next!=nullptr&&p->next->val<=q->val))) p = p->next;
            if (p == nullptr) break;
            auto tmp = p->next;
            p->next = q;
            p = q;
            q = tmp;
        }
        return res;
    }
};
