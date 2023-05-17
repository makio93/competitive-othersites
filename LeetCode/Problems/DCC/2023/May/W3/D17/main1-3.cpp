// 解説AC3

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
    int pairSum(ListNode* head) {
        auto fast = head->next, slow = fast;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto nnode = slow, pnode = (ListNode*)nullptr;
        while (slow) {
            nnode = slow->next;
            slow->next = pnode;
            pnode = slow;
            slow = nnode;
        }
        slow = head;
        int res = 0;
        while (pnode) {
            res = max(res, slow->val+pnode->val);
            slow = slow->next;
            pnode = pnode->next;
        }
        return res;
    }
};
