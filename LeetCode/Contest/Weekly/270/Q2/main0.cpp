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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        auto p = head;
        while (p != nullptr) {
            p = p->next;
            ++n;
        }
        if (n == 1) return nullptr;
        p = head;
        auto q = p->next;
        int ntar = n / 2, ncnt = 0;
        while (ncnt < ntar-1) {
            p = q;
            q = q->next;
            ++ncnt;
        }
        if (q == nullptr) p->next = nullptr;
        else p->next = q->next;
        return head;
    }
};
