#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int d;
        Node *one = nullptr, *zero = nullptr, *rev = nullptr;
        int nums;
        Node(int d=18, Node* rev=nullptr) : d(d), rev(rev) {}
    };
    vector<int> ans;
    vector<vector<int>> g, qid;
    vector<Node*> pnode;
    Node *rnode;
    void dfs(vector<vector<int>>& queries, int v, int p=-1) {
        auto ptr = rnode;
        for (int i=18; i>=0; --i) {
            if (((v>>i)&1) == 1) {
                if (ptr->one == nullptr) {
                    ptr->one = new Node(i-1);
                    ptr->one->rev = ptr;
                }
                ptr = ptr->one;
            }
            else {
                if (ptr->zero == nullptr) {
                    ptr->zero = new Node(i-1);
                    ptr->zero->rev = ptr;
                }
                ptr = ptr->zero;
            }
        }
        ptr->nums = v;
        for (int t : qid[v]) {
            int vali = queries[t][1];
            auto ptr2 = rnode;
            for (int i=18; i>=0; --i) {
                if (((vali>>i)&1) == 1) {
                    if (ptr2->zero != nullptr) ptr2 = ptr2->zero;
                    else ptr2 = ptr2->one;
                }
                else {
                    if (ptr2->one != nullptr) ptr2 = ptr2->one;
                    else ptr2 = ptr2->zero;
                }
            }
            ans[t] = vali ^ ptr2->nums;
        }
        for (int t : g[v]) if (t != p) dfs(queries, t, v);
        for (int i=0; i<=18; ++i) {
            if (ptr->one==nullptr && ptr->zero==nullptr) {
                auto ptr2 = ptr->rev;
                if (ptr2->one == ptr) ptr2->one = nullptr;
                if (ptr2->zero == ptr) ptr2->zero = nullptr;
                ptr = ptr2;
            }
            else break;
        }
    }
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size(), q = queries.size(), root = -1;
        g = vector<vector<int>>(n);
        for (int i=0; i<n; ++i) {
            if (parents[i] == -1) root = i;
            else g[parents[i]].push_back(i);
        }
        pnode = vector<Node*>(n, nullptr);
        ans = vector<int>(q);
        qid = vector<vector<int>>(n);
        for (int i=0; i<q; ++i) qid[queries[i][0]].push_back(i);
        rnode = new Node();
        dfs(queries, root);
        return ans;
    }
};

int main() {
    
    return 0;
}
