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
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> pst;
        auto ptr = head;
        while (ptr!=nullptr && pst.find(ptr)==pst.end()) {
            pst.insert(ptr);
            ptr = ptr->next;
        }
        return ptr;
    }
};
