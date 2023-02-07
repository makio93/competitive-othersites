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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 自力AC

class Solution {
    TreeNode* bst(vector<int>& vals, int li, int ri) {
        if (ri-li <= 0) return nullptr;
        else if (ri-li <= 1) return new TreeNode(vals[li]);
        else {
            int mi = li + (ri-li) / 2;
            return new TreeNode(vals[mi], bst(vals, li, mi), bst(vals, mi+1, ri));
        }
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vals;
        auto ptr = head;
        while (ptr != nullptr) {
            vals.push_back(ptr->val);
            ptr = ptr->next;
        }
        return bst(vals, 0, vals.size());
    }
};
