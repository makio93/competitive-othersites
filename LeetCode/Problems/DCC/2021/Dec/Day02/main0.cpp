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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        auto evenhead = head->next, odd = head, even = head->next;
        while (odd!=nullptr && even!=nullptr) {
            odd->next = even->next;
            if (odd->next == nullptr) break;
            odd = odd->next;
            even->next = odd->next;
            if (even->next == nullptr) break;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};
