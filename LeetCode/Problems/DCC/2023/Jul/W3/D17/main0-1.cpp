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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> d1, d2;
        while (l1) {
            d1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            d2.push_back(l2->val);
            l2 = l2->next;
        }
        reverse(d1.begin(), d1.end());
        reverse(d2.begin(), d2.end());
        if (d1.size() > d2.size()) swap(d1, d2);
        while (d1.size() < d2.size()) d1.push_back(0);
        int n = d1.size(), val = 0;
        vector<int> res(n);
        for (int i=0; i<n; ++i) {
            val += d1[i] + d2[i];
            res[i] = val % 10;
            val /= 10;
        }
        while (val > 0) {
            res.push_back(val%10);
            val /= 10;
        }
        n = res.size();
        ListNode *root = new ListNode, *vnode = root;
        for (int i=n-1; i>=0; --i) {
            vnode->next = new ListNode(res[i]);
            vnode = vnode->next;
        }
        return root->next;
    }
};
