// 本番AC

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int y = 0, x = 0, d = 0;
        const vector<int> dy = { 0, 1, 0, -1 }, dx = { 1, 0, -1, 0 };
        while (head != nullptr) {
            res[y][x] = head->val;
            head = head->next;
            if (head == nullptr) break;
            while (y+dy[d]<0 || y+dy[d]>=m || x+dx[d]<0 || x+dx[d]>=n || res[y+dy[d]][x+dx[d]]!=-1) d = (d+1) % 4;
            y += dy[d], x += dx[d];
        }
        return res;
    }
};
