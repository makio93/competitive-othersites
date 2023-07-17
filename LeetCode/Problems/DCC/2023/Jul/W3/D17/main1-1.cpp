// 解説AC1

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int val = 0;
        ListNode *vnode = new ListNode;
        while (!s1.empty() || !s2.empty() || val>0) {
            if (!s1.empty()) {
                val += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                val += s2.top();
                s2.pop();
            }
            vnode->val = val % 10;
            val /= 10;
            vnode = new ListNode(0, vnode);
        }
        return vnode->next;
    }
};
