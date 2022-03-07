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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0, list1);
        auto head = dummy, p1 = list1, p2 = list2;
        while (p1!=nullptr && p2!=nullptr) {
            if (p1->val <= p2->val) {
                head->next = p1;
                head = head->next;
                p1 = p1->next;
            }
            else {
                head->next = p2;
                head = head->next;
                p2 = p2->next;
                head->next = p1;
            }
        }
        if (p1 != nullptr) head->next = p1;
        else if (p2 != nullptr) head->next = p2;
        return dummy->next;
    }
};
