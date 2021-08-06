#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// 自力AC

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            queue<Node*> next_que;
            vector<int> next_trav;
            while (!que.empty()) {
                auto ptr = que.front(); que.pop();
                if (ptr != nullptr) {
                    next_trav.push_back(ptr->val);
                    for (auto tptr : ptr->children) next_que.push(tptr);
                }
            }
            swap(que, next_que);
            if (!next_trav.empty()) res.push_back(next_trav);
        }
        return res;
    }
};
