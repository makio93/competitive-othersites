// 学習1回目,自力AC

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
        queue<Node*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int ql = que.size();
            Node* lnode = NULL;
            while (ql > 0) {
                auto vnode = que.front(); que.pop();
                if (lnode != NULL) lnode->next = vnode;
                lnode = vnode;
                if (vnode->left != NULL) que.push(vnode->left);
                if (vnode->right != NULL) que.push(vnode->right);
                --ql;
            }
        }
        return root;
    }
};
