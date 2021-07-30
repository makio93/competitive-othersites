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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto p = head, q = head;
        for (int i=0; i<n; ++i) p = p->next;
        if (p == nullptr) return head->next;
        while (p->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
    }
};
