#include <bits/stdc++.h>
using namespace std;

// 本番TLE

class Solution {
    int INF = (int)(1e9);
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        vector<int> dist(1001, INF);
        queue<int> que;
        dist[start] = 0;
        que.push(start);
        while (!que.empty()) {
            int xval = que.front(); que.pop();
            int d = dist[xval], nd = d + 1;
            for (int i=0; i<n; ++i) {
                vector<int> tvals = { xval+nums[i], xval-nums[i], xval^nums[i] };
                for (int tval : tvals) {
                    if (tval == goal) return nd;
                    if (tval<0 || tval>1000) continue;
                    if (dist[tval] <= nd) continue;
                    dist[tval] = nd;
                    que.push(tval);
                }
            }
        }
        return -1;
    }
};
