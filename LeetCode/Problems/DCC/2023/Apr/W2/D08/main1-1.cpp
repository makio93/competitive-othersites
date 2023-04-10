// 解説AC1

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
    unordered_map<Node*, Node*> memo;
    Node* dfs(Node* vnode) {
        if (memo.find(vnode) != memo.end()) return memo[vnode];
        Node* cnode = new Node(vnode->val);
        memo[vnode] = cnode;
        for (const auto& tnode : vnode->neighbors) cnode->neighbors.push_back(dfs(tnode));
        return cnode;
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        return dfs(node);
    }
};
