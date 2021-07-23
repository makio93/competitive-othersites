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

// 自力解答,AC

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *oddHead = head, *evenHead = head->next, *odd = oddHead, *even = evenHead;
        while (odd->next != nullptr) {
            odd->next = odd->next->next;
            if (odd->next != nullptr) odd = odd->next;
            if (even->next != nullptr) even->next = even->next->next;
            even = even->next;
        }
        odd->next = evenHead;
        return oddHead;
    }
};
