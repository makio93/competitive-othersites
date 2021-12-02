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
    ListNode* partition(ListNode* head, int x) {
        ListNode *shigh = nullptr, *slow = nullptr, *lhigh = nullptr, *llow = nullptr, *pnode = head;
        while (pnode != nullptr) {
            if (pnode->val < x) {
                if (llow != nullptr) llow->next = pnode;
                llow = pnode;
                if (slow == nullptr) slow = pnode;
            }
            else {
                if (lhigh != nullptr) lhigh->next = pnode;
                lhigh = pnode;
                if (shigh == nullptr) shigh = pnode;
            }
            pnode = pnode->next;
        }
        if (llow!=nullptr && shigh!=nullptr) {
            llow->next = shigh;
            lhigh->next = nullptr;
            return slow;
        }
        else return head;
    }
};

int main(){
    
    return 0;
}
