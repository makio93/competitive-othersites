#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 自力AC

class Solution {
    unordered_set<ListNode*> visited;
    ListNode *search(ListNode *vnode) {
        if (vnode == NULL) return vnode;
        if (visited.find(vnode) != visited.end()) return vnode;
        visited.insert(vnode);
        return search(vnode->next);
    }
public:
    ListNode *detectCycle(ListNode *head) {
        return search(head);
    }
};
