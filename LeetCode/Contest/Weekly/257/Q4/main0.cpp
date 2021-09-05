#include <bits/stdc++.h>
using namespace std;

// 本番AC

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
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        UnionFind u(n);
        unordered_map<int, set<int>> pids;
        for (int i=0; i<n; ++i) {
            int val = nums[i];
            for (int j=2; j*j<=val; ++j) if (val%j == 0) {
                if (pids.find(j) != pids.end()) u.unite(i, *pids[j].rbegin());
                pids[j].insert(i);
                while (val%j == 0) val /= j;
            }
            if (val > 1) {
                if (pids.find(val) != pids.end()) u.unite(i, *pids[val].rbegin());
                pids[val].insert(i);
            }
        }
        unordered_map<int, set<int>> gids;
        for (int i=0; i<n; ++i) gids[u.find(i)].insert(i);
        auto tars = nums;
        sort(tars.begin(), tars.end());
        for (auto p : gids) {
            vector<int> v1, v2;
            for (int vid : p.second) {
                v1.push_back(nums[vid]);
                v2.push_back(tars[vid]);
            }
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            if (v1 != v2) return false;
        }
        return true;
    }
};
