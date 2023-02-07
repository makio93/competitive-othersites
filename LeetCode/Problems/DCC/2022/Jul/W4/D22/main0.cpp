// 自力AC1

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
    ListNode* partition(ListNode* head, int x) {
        auto itr = head;
        auto calc = [](auto calc, ListNode* vnode, int x) -> bool {
            if (vnode == nullptr) return false;
            if (vnode->val < x) return true;
            if (calc(calc, vnode->next, x)) {
                swap(vnode->val, vnode->next->val);
                return true;
            }
            else return false;
        };
        while (itr) {
            if (itr->val<x || (itr->val>=x&&calc(calc,itr,x))) itr = itr->next;
            else break;
        }
        return head;
    }
};
