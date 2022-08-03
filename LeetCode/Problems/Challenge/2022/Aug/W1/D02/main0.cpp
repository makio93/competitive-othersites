// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i=0; i<n; ++i) pq.emplace(matrix[i][0], i*n);
        int res = 0;
        while (!pq.empty()) {
            auto pi = pq.top(); pq.pop();
            int val = pi.first, y = pi.second / n, x = pi.second % n;
            --k;
            if (k == 0) {
                res = val;
                break;
            }
            ++x;
            if (x < n) pq.emplace(matrix[y][x], y*n+x);
        }
        return res;
    }
};
