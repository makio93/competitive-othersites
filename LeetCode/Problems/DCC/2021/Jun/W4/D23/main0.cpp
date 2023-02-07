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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right-left > 0) {
            auto p = head, q = (ListNode*)nullptr, fr = (ListNode*)nullptr, to = (ListNode*)nullptr;
            int ncnt = 1;
            while (ncnt < left) {
                q = p; p = p->next;
                ++ncnt;
            }
            fr = q; to = p;
            while (ncnt <= right) {
                auto t = p->next;
                if (ncnt != left) p->next = q;
                if (ncnt == right) {
                    if (fr != nullptr) fr->next = p;
                    else head = p;
                    to->next = t;
                }
                q = p; p = t;
                ++ncnt;
            }
        }
        return head;
    }
};
