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

// 自力AC

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<tuple<int, int, ListNode*>, vector<tuple<int, int, ListNode*>>, greater<tuple<int, int, ListNode*>>> pq;
        for (int i=0; i<n; ++i) if (lists[i] != nullptr) pq.emplace(lists[i]->val, i, lists[i]);
        ListNode *res = nullptr, *head = nullptr;
        while (!pq.empty()) {
            auto [vi, ki, pti] = pq.top(); pq.pop();
            if (head == nullptr) res = head = pti;
            else {
                head->next = pti;
                head = head->next;
            }
            if (head->next != nullptr) pq.emplace(head->next->val, ki, head->next);
        }
        return res;
    }
};
