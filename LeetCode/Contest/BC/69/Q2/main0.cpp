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

// バチャ本番AC

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vals;
        while (head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        int n = vals.size(), res = 0;
        for (int i=0; i<n/2; ++i) res = max(res, vals[i]+vals[n-i-1]);
        return res;
    }
};
