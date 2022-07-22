// 自力AC2

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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        ListNode *fhead = nullptr, *shead = nullptr, *ftail = nullptr, *stail = nullptr, *itr = head;
        while (itr) {
            if (itr->val < x) {
                if (fhead == nullptr) fhead = ftail = itr;
                else ftail = ftail->next = itr;
            }
            else {
                if (shead == nullptr) shead = stail = itr;
                else stail = stail->next = itr;
            }
            itr = itr->next;
        }
        if (fhead == nullptr) head = shead;
        else {
            head = fhead;
            ftail->next = shead;
        }
        if (stail != nullptr) stail->next = nullptr;
        return head;
    }
};
