// 

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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        auto p = head;
        while (p != nullptr) {
            p = p->next;
            ++n;
        }
        p = head;
        auto q = head;
        int cnt = 0;
        while (cnt != k-1) {
            p = p->next;
            ++cnt;
        }
        cnt = 0;
        while (cnt != n-k) {
            q = q->next;
            ++cnt;
        }
        swap(p->val, q->val);
        return head;
    }
};
