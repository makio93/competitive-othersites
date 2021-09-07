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

// 自力AC,iterative解

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *lp = nullptr, *cp = head;
        while (cp != nullptr) {
            ListNode *tp = cp->next;
            cp->next = lp;
            lp = cp;
            cp = tp;
        }
        return lp;
    }
};
