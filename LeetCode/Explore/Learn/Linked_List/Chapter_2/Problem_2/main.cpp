#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 自力解答,空間計算量O(1),AC

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL) fast = fast->next;
        }
        return false;
    }
};
