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
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        UnionFind u(n);
        unordered_map<int, vector<int>> plst;
        for (int i=0; i<n; ++i) {
            int nval = nums[i];
            vector<int> primes;
            for (int j=2; j*j<=nval; ++j) if (nval%j == 0) {
                primes.push_back(j);
                while (nval%j == 0) nval /= j;
            }
            if (nval > 1) primes.push_back(nval);
            int plen = primes.size();
            for (int j=0; j<plen; ++j) {
                if (plst.find(primes[j]) != plst.end()) u.unite(plst[primes[j]].back(), i);
                plst[primes[j]].push_back(i);
                if (j-1 >= 0) u.unite(plst[primes[j-1]].front(), plst[primes[j]].front());
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) res = max(res, u.size(i));
        return res;
    }
};
