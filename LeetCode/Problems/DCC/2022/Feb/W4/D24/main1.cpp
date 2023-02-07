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
    ListNode* split(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre_mid = dummy;
        while (head!=nullptr && head->next!=nullptr) {
            pre_mid = pre_mid->next;
            head = head->next->next;
        }
        ListNode* res = pre_mid->next;
        pre_mid->next = nullptr;
        return res;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0, left);
        ListNode* ptr = dummy;
        while (left!=nullptr && right!=nullptr) {
            if (left->val <= right->val) {
                left = left->next;
                ptr = ptr->next;
            }
            else {
                ptr->next = right;
                right = right->next;
                ptr = ptr->next;
                ptr->next = left;
            }
        }
        if (left != nullptr) ptr->next = left;
        else if (right != nullptr) ptr->next = right;
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;
        auto mid = split(head);
        auto left = sortList(head), right = sortList(mid);
        return merge(left, right);
    }
};
