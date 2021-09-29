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

// 自力AC,解法2,Space:O(k)

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, nullptr);
        int n = 0;
        auto p = head;
        while (p != nullptr) {
            p = p->next;
            ++n;
        }
        int q = n / k, r = n % k;
        p = head;
        for (int i=0; i<k; ++i) {
            res[i] = p;
            int len = (i < r) ? q+1 : q;
            if (len == 0) continue;
            for (int j=0; j+1<len; ++j) p = p->next;
            auto tmp = p->next;
            p->next = nullptr;
            p = tmp;
        }
        return res;
    }
};
