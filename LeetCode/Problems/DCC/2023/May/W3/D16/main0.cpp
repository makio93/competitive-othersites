// 自力AC

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
        if (head == nullptr) return head;
        auto dummy = new ListNode(0, head), p = dummy, q = p->next;
        while (q && q->next) {
            q = q->next;
            p->next->next = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = p->next;
        }
        return dummy->next;
    }
};
