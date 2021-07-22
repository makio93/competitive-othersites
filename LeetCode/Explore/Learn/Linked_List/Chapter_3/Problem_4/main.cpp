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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head, *q = nullptr, *res = head;
        while (p!=nullptr && p->val==val) {
            q = p;
            p = p->next;
        }
        res = p;
        while (p != nullptr) {
            if (p->val == val) q->next = p->next;
            else q = p;
            p = p->next;
        }
        return res;
    }
};
