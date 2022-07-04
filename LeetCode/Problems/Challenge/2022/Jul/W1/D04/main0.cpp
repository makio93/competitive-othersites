// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<unordered_set<int>> g(n);
        vector<int> din(n);
        for (int i=0; i<n; ++i) {
            if (i-1>=0 && ratings[i]>ratings[i-1]) {
                g[i-1].insert(i);
                din[i]++;
            }
            if (i+1<n && ratings[i]>ratings[i+1]) {
                g[i+1].insert(i);
                din[i]++;
            }
        }
        vector<int> dist(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i=0; i<n; ++i) if (din[i] == 0) {
            dist[i] = 1;
            pq.emplace(1, i);
        }
        while (!pq.empty()) {
            auto pi = pq.top(); pq.pop();
            int di = pi.first, vi = pi.second;
            auto itr = g[vi].begin();
            while (itr != g[vi].end()) {
                int ti = *itr;
                if (din[ti] == 1) {
                    dist[ti] = di + 1;
                    pq.emplace(di+1, ti);
                }
                din[ti]--;
                itr = g[vi].erase(itr);
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) res += dist[i];
        return res;
    }
};
