// 自力AC

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        auto root = node;
        if (root == nullptr) return root;
        auto res = new Node(root->val);
        unordered_map<int, Node*> visited;
        queue<Node*> que;
        visited[root->val] = res;
        que.push(root);
        while (!que.empty()) {
            Node *vnode = que.front(); que.pop();
            Node *rnode = visited[vnode->val];
            for (Node* tnode : vnode->neighbors) {
                if (visited.find(tnode->val) == visited.end()) {
                    visited[tnode->val] = new Node(tnode->val);
                    que.push(tnode);
                }
                rnode->neighbors.push_back(visited[tnode->val]);
            }
        }
        return res;
    }
};
