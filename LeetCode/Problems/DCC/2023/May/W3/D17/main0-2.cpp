// 自力AC2

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
        auto dummy = new ListNode(0, head), tnode = dummy;
        int res = 0;
        function<void(ListNode*)> dfs = [&](ListNode* vnode) {
            if (!tnode->next) {
                tnode = vnode->next;
                res = max(res, vnode->val+tnode->val);
                return;
            }
            tnode = tnode->next->next;
            dfs(vnode->next);
            tnode = tnode->next;
            if (tnode) res = max(res, vnode->val+tnode->val);
        };
        dfs(dummy);
        delete dummy;
        return res;
    }
};
