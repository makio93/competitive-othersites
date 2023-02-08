// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dist(n);
        queue<pair<int, int>> que;
        for (int i=0; i<n; ++i) {
            if (i-1>=0 && ratings[i-1]<ratings[i]) continue;
            if (i+1<n && ratings[i+1]<ratings[i]) continue;
            dist[i] = 1;
            que.emplace(i, 1);
        }
        while (!que.empty()) {
            int id = que.front().first, di = que.front().second; que.pop();
            if (dist[id] != di) continue;
            int ndi = di + 1;
            if (id-1>=0 && ratings[id-1]>ratings[id] && dist[id-1]<ndi) {
                dist[id-1] = ndi;
                que.emplace(id-1, ndi);
            }
            if (id+1<n && ratings[id+1]>ratings[id] && dist[id+1]<ndi) {
                dist[id+1] = ndi;
                que.emplace(id+1, ndi);
            }
        }
        return accumulate(dist.begin(), dist.end(), 0);
    }
};
