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

// 本番AC

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int now = 0, pval = -1;
        set<int> pids;
        auto itr = head;
        while (itr != nullptr) {
            if (pval!=-1 && itr->next!=nullptr) {
                if ((pval<itr->val&&itr->next->val<itr->val) || (pval>itr->val&&itr->next->val>itr->val)) pids.insert(now);
            }
            pval = itr->val;
            ++now;
            itr = itr->next;
        }
        vector<int> res = { -1, -1 };
        if ((int)(pids.size()) >= 2) {
            res[0] = (int)(1e9);
            for (auto itr=pids.begin(); next(itr)!=pids.end(); ++itr) res[0] = min(res[0], *next(itr)-*itr);
            res[1] = *pids.rbegin() - *pids.begin();
        }
        return res;
    }
};
