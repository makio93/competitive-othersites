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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *p2 = nullptr;
        int ncnt = 0;
        while (p != nullptr) {
            p = p->next;
            ++ncnt;
            if (p2==nullptr && ncnt==n+1) p2 = head;
            else if (p2 != nullptr) p2 = p2->next;
        }
        if (p2 != nullptr) {
            auto p3 = p2->next;
            p2->next = p3->next;
        }
        else head = head->next;
        return head;
    }
};

int main(){
    
    return 0;
}
