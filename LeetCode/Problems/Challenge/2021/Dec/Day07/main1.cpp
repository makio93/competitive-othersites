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

// 解説AC,Recursiveな解法

class Solution {
    int calc(ListNode* vnode, int val=0) { return vnode ? calc(vnode->next, val*2+vnode->val) : val; }
public:
    int getDecimalValue(ListNode* head) { return calc(head); }
};
