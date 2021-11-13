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
        while (head!=nullptr && head->val==val) head = head->next;
        if (head == nullptr) return head;
        auto p = head;
        while (p != nullptr) {
            while (p->next!=nullptr && p->next->val==val) p->next = p->next->next;
            p = p->next;
        }
        return head;
    }
};
