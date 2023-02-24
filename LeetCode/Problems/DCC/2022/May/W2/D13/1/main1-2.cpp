// 学習1回目,Space:O(1),解説AC

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
        Node *node = root, *head = NULL, *tail = NULL;
        while (node) {
            if (node->left) {
                if (tail) tail = tail->next = node->left;
                else head = tail = node->left;
            }
            if (node->right) {
                if (tail) tail = tail->next = node->right;
                else head = tail = node->right;
            }
            if (node->next) node = node->next;
            else {
                node = head;
                head = tail = NULL;
            }
        }
        return root;
    }
};
