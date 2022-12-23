// 自力AC1

#include <bits/stdc++.h>
using namespace std;

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
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& li, string& ri) -> bool {
            return li.length() < ri.length();
        });
        UnionFind uf(n);
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            if (words[j].substr(words[j].length()-words[i].length()) == words[i]) {
                uf.unite(i, j);
                break;
            }
        }
        unordered_map<int, int> glst;
        for (int i=0; i<n; ++i) glst[uf.find(i)] = max(glst[uf.find(i)], (int)(words[i].length()));
        int res = 0;
        for (auto& pi : glst) res += pi.second + 1;
        return res;
    }
};
