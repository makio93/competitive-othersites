#include <bits/stdc++.h>
using namespace std;

// 自力AC

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        int sz = 0;
        auto ptr = head;
        while (ptr != nullptr) {
            ++sz;
            ptr = ptr->next;
        }
        ptr = head;
        ListNode *ptail = nullptr, *nhead = head, *ptr2 = nullptr;
        bool rev = true;
        for (int i=0; i<=sz; ++i) {
            if (!rev) break;
            if (i==sz && i%k!=0) break;
            if (i==0 || i%k!=0) {
                auto tmp = ptr->next;
                ptr->next = ptr2;
                ptr2 = ptr;
                ptr = tmp;
            }
            else {
                if (i+k > sz) rev = false;
                if (i/k == 1) head = ptr2;
                else ptail->next = ptr2;
                ptail = nhead;
                nhead = ptr;
                if (!rev) ptail->next = ptr;
                ptr2 = ptr;
                if (ptr != nullptr) ptr = ptr->next;
            }
        }
        return head;
    }
};
