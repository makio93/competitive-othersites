#include <bits/stdc++.h>
using namespace std;

// 自力AC

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0) : d(n, -1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return (d[x] = find(d[x]));
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return (find(x) == find(y)); }
    int size(int x) { return -d[find(x)]; }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<string> emails;
        unordered_map<string, int> names;
        for (int i=0; i<n; ++i) for (int j=1; j<(int)(accounts[i].size()); ++j) {
            emails.push_back(accounts[i][j]);
            if (names.find(accounts[i][j]) == names.end()) names[accounts[i][j]] = i;
        }
        sort(emails.begin(), emails.end());
        emails.erase(unique(emails.begin(), emails.end()), emails.end());
        unordered_map<string, int> eids;
        for (int i=0; i<(int)(emails.size()); ++i) eids[emails[i]] = i;
        UnionFind d((int)(emails.size()));
        for (int i=0; i<n; ++i) for (int j=2; j<(int)(accounts[i].size()); ++j) d.unite(eids[accounts[i][1]], eids[accounts[i][j]]);
        map<int, set<string>> rmemo;
        for (int i=0; i<(int)(emails.size()); ++i) rmemo[names[emails[d.find(i)]]].insert(emails[i]);
        vector<vector<string>> res;
        for (auto pi : rmemo) {
            res.push_back({ accounts[pi.first][0] });
            res.back().insert(res.back().end(), pi.second.begin(), pi.second.end());
        }
        return res;
    }
};
