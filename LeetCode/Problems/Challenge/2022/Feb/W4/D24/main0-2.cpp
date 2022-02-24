// Time:O(nlogn),Space:O(nlogn),AC

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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;
        vector<ListNode*> nlst;
        while (head != nullptr) {
            nlst.push_back(head);
            head = head->next;
        }
        sort(nlst.begin(), nlst.end(), [](ListNode* a, ListNode* b) { return a->val < b->val; });
        int m = nlst.size();
        for (int i=0; i<m; ++i) {
            if (i+1 < m) nlst[i]->next = nlst[i+1];
            else nlst[i]->next = nullptr;
        }
        return nlst.front();
    }
};
