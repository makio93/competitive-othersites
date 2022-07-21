// 解説AC1

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        function<ListNode*(int,int,ListNode*,ListNode*)> recur = [&recur](int m, int n, ListNode* left, ListNode* right) -> ListNode* {
            if (m > 1) return recur(m-1, n-1, left->next, right->next);
            else if (n > 1) {
                auto lnode = recur(m, n-1, left, right->next);
                if (lnode == nullptr) return lnode;
                if (right==lnode || right->next==lnode) return nullptr;
                swap(lnode->val, right->val);
                return lnode->next;
            }
            else if (left != right) {
                swap(left->val, right->val);
                return left->next;
            }
            else return nullptr;
        };
        recur(left, right, head, head);
        return head;
    }
};
