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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode *ptr = dummy, *ltmp = nullptr;
        for (int i=0; i<left-1; ++i) ptr = ptr->next;
        ltmp = ptr;
        ptr = ptr->next;
        ListNode *nptr = ptr->next;
        for (int i=left; i<right; ++i) {
            ListNode *nnptr = nptr->next;
            nptr->next = ptr;
            ptr = nptr;
            nptr = nnptr;
        }
        ltmp->next->next = nptr;
        ltmp->next = ptr;
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};
