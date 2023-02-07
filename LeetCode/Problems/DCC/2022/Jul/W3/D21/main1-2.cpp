// 解説AC2

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *cur = head, *prev = nullptr;
        while (left > 1) {
            prev = cur;
            cur = cur->next;
            --left; --right;
        }
        ListNode *first = prev, *tail = cur;
        prev = cur;
        cur = cur->next;
        while (right > 1) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            --right;
        }
        if (first != nullptr) first->next = prev;
        else head = prev;
        tail->next = cur;
        return head;
    }
};
