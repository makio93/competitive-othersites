// 解説AC

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
        Node *vnode = root, *head = NULL, *tail = NULL;
        while (vnode) {
            if (vnode->left) {
                if (head) tail = tail->next = vnode->left;
                else head = tail = vnode->left;
            }
            if (vnode->right) {
                if (head) tail = tail->next = vnode->right;
                else head = tail = vnode->right;
            }
            vnode = vnode->next;
            if (!vnode) {
                vnode = head;
                head = tail = NULL;
            }
        }
        return root;
    }
};
