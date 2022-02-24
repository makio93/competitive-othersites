// Time:O(nlogn),Space:O(1),WA

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
    void node_swap(ListNode** lnode, ListNode** rnode) {
        auto ltmp = &(*lnode)->next, rtmp = &(*rnode)->next;
        swap(*lnode, *rnode);
        swap(*ltmp, *rtmp);
        swap(lnode, rnode);
    }
    void merge_sort(ListNode** lnode, ListNode* rnode=nullptr) {
        if (*lnode==rnode || (*lnode)->next==rnode) return;
        ListNode **slow = lnode, **fast = &(*lnode)->next;
        while (*fast != rnode) {
            slow = &(*slow)->next;
            fast = &(*fast)->next;
            if (*fast != rnode) fast = &(*fast)->next;
        }
        merge_sort(lnode, *slow);
        merge_sort(slow, rnode);
        fast = slow, slow = lnode;
        while (((*fast)!=rnode&&(*fast)->next!=rnode) || *slow!=*fast) {
            if ((*slow)->val > (*fast)->val) node_swap(slow, fast);
            if (*slow!=*fast && (*slow)->next!=*fast && (*slow)->next->val>(*fast)->val) slow = &(*slow)->next;
            else if ((*fast)->next != rnode) fast = &(*fast)->next;
            else slow = &(*slow)->next;
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        merge_sort(&head);
        return head;
    }
};
