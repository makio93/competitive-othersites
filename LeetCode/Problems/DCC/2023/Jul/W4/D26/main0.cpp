// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size(), li = 0, ri = INF;
        while (ri-li > 1) {
            int ci = ri - (ri-li) / 2, sum = 0;
            for (int i=0; i<n-1; ++i) sum += (dist[i] + ci-1) / ci;
            if (sum + (dist[n-1] / (double)ci) <= hour) ri = ci;
            else li = ci;
        }
        if (ri == INF) return -1;
        else return ri;
    }
};
