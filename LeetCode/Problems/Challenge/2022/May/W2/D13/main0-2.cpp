// 自力AC2

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        unordered_map<int, Node*> rnlst;
        auto dfs = [&](auto dfs, Node* vnode, int di=0) -> void {
            if (vnode == NULL) return;
            if (rnlst.find(di) == rnlst.end()) rnlst[di] = vnode;
            else {
                vnode->next = rnlst[di];
                rnlst[di] = vnode;
            }
            dfs(dfs, vnode->right, di+1);
            dfs(dfs, vnode->left, di+1);
        };
        dfs(dfs, root);
        return root;
    }
};
