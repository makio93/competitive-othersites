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

// 解説AC,Iterativeな解法

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while (head != nullptr) {
            res = res * 2 + head->val;
            head = head->next;
        }
        return res;
    }
};
