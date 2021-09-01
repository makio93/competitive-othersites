#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
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
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), res = 1;
        UnionFind d(n);
        for (int i=0; i<n; ++i) if (d.size(i) == 1) {
            int now = i, cnt = 1;
            while (d.size(now) == cnt) {
                d.unite(now, nums[now]);
                now = nums[now];
                ++cnt;
            }
            res = max(res, d.size(now));
        }
        return res;
    }
};
