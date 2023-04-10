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
        if (node == NULL) return NULL;
        Node* res = new Node(node->val);
        queue<pair<Node*, Node*>> que;
        unordered_map<int, Node*> vst;
        que.emplace(node, res);
        vst[node->val] = res;
        while (!que.empty()) {
            auto [vnode, cnode] = que.front(); que.pop();
            for (const auto& nnode : vnode->neighbors) {
                if (vst.find(nnode->val) == vst.end()) {
                    vst[nnode->val] = new Node(nnode->val);
                    que.emplace(nnode, vst[nnode->val]);
                }
                cnode->neighbors.push_back(vst[nnode->val]);
            }
        }
        return res;
    }
};
