// 学習1回目,Space:O(1),自力WA

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
    Node* least_child(Node* node) {
        if (node == NULL) return NULL;
        if (node->right != NULL) return node->right;
        else if (node->left != NULL) return node->left;
        else return NULL;
    }
    void dfs(Node* vnode, Node* lnode=NULL) {
        if (lnode != NULL) lnode->next = vnode;
        if (vnode->left != NULL) dfs(vnode->left, least_child(lnode));
        if (vnode->right != NULL) {
            if (vnode->left == NULL) dfs(vnode->right, least_child(lnode));
            else dfs(vnode->right, vnode->left);
        }
    }
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        dfs(root);
        return root;
    }
};
