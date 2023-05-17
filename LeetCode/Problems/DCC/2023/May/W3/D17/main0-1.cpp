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
    int pairSum(ListNode* head) {
        vector<int> vlst;
        while (head) {
            vlst.push_back(head->val);
            head = head->next;
        }
        int res = 0, n = vlst.size();
        for (int i=0; i<n/2; ++i) res = max(res, vlst[i]+vlst[n-1-i]);
        return res;
    }
};
