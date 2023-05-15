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
        ListNode *p1 = nullptr, *p2 = nullptr;
        for (auto q=head; q!=nullptr; q=q->next) {
            if (p2 == nullptr) {
                if (--k == 0) {
                    p1 = q;
                    p2 = head;
                }
            }
            else p2 = p2->next;
        }
        swap(p1->val, p2->val);
        return head;
    }
};
