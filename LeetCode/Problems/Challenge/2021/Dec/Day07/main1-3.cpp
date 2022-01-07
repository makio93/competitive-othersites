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

// 解説AC,文字列に変換

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s;
        while (head != nullptr) {
            s += (char)(head->val + '0');
            head = head->next;
        }
        int res = stoull(s, 0UL, 2);
        return res;
    }
};
