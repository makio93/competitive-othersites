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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        int len = 0;
        auto p = head, tail = p;
        while (p != nullptr) {
            if (p->next == nullptr) tail = p;
            p = p->next;
            ++len;
        }
        k %= len;
        if (k == 0) return head;
        p = head;
        int cnt = 0;
        while (cnt != len-k-1) {
            p = p->next;
            ++cnt;
        }
        auto res = p->next;
        p->next = nullptr;
        tail->next = head;
        return res;
    }
};
