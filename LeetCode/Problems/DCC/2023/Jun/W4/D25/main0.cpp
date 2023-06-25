// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        priority_queue<tuple<int, int, ll>> pq;
        vector<unordered_map<int, ll>> dists(n);
        dists[start][fuel] += 1;
        pq.emplace(fuel, start, dists[start][fuel]);
        while (!pq.empty()) {
            auto [di, vi, ri] = pq.top(); pq.pop();
            if (dists[vi][di] != ri) continue;
            for (int ti=0; ti<n; ++ti) if (ti != vi) {
                int ddi = abs(locations[ti] - locations[vi]);
                if (ddi > di) continue;
                int ndi = di - ddi;
                dists[ti][ndi] = (dists[ti][ndi] + ri) % mod;
                pq.emplace(ndi, ti, dists[ti][ndi]);
            }
        } 
        ll res = 0;
        for (const auto& pi : dists[finish]) res = (res + pi.second) % mod;
        return (int)res;
    }
};
