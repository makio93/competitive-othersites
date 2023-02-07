// 解説AC

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
        ListNode *fhead = new ListNode(), *shead = new ListNode();
        ListNode *fitr = fhead, *sitr = shead;
        while (head) {
            if (head->val < x) {
                fitr->next = head;
                fitr = fitr->next;
            }
            else {
                sitr->next = head;
                sitr = sitr->next;
            }
            head = head->next;
        }
        sitr->next = nullptr;
        fitr->next = shead->next;
        head = fhead->next;
        delete fhead;
        delete shead;
        return head;
    }
};
