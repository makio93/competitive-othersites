// 解説AC2

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
    int nodeCount(ListNode* head) {
        int res = 0;
        while (head != nullptr) {
            ++res;
            head = head->next;
        }
        return res;
    }
    ListNode* split(ListNode* ptr, int size, ListNode*& sublist) {
        auto left = ptr, right = ptr->next;
        for (int i=1; i<size&&(left->next!=nullptr||right->next!=nullptr); ++i) {
            if (right->next != nullptr) {
                right = right->next;
                if (right->next != nullptr) right = right->next;
            }
            if (left->next != nullptr) left = left->next;
        }
        auto res = left->next;
        sublist = right->next;
        left->next = right->next = nullptr;
        return res;
    }
    void merge(ListNode* ptr, ListNode* mid, ListNode*& tail) {
        auto dummy = new ListNode(), head = dummy;
        while (ptr!=nullptr && mid!=nullptr) {
            if (ptr->val <= mid->val) {
                head->next = ptr;
                ptr = ptr->next;
            }
            else {
                head->next = mid;
                mid = mid->next;
            }
            head = head->next;
        }
        if (ptr != nullptr) head->next = ptr;
        else if (mid != nullptr) head->next = mid;
        while (head->next != nullptr) head = head->next;
        tail->next = dummy->next;
        tail = head;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto tail = new ListNode(), sublist = new ListNode();
        int n = nodeCount(head);
        auto ptr = head, dummy = new ListNode(0, head);
        for (int i=1; i<n; i*=2) {
            tail = dummy;
            while (ptr != nullptr) {
                if (ptr->next == nullptr) {
                    tail->next = ptr;
                    ptr = ptr->next;
                }
                else {
                    merge(ptr, split(ptr, i, sublist), tail);
                    ptr = sublist;
                }
            }
            ptr = dummy->next;
        }
        return dummy->next;
    }
};
