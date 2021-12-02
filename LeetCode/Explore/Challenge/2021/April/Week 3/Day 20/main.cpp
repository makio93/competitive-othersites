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

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            auto pnode = st.top(); st.pop();
            res.push_back(pnode->val);
            for (int i=(int)(pnode->children.size())-1; i>=0; --i) if (pnode->children[i] != nullptr) st.push(pnode->children[i]);
        }
        return res;
    }
};

int main(){
    
    return 0;
}
