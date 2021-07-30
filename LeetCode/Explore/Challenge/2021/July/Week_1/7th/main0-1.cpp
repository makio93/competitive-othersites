#include <bits/stdc++.h>
using namespace std;

// 自力AC1

class Solution {
    const int INV = (int)(-1e9) - 5;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(matrix[0][0], 0);
        matrix[0][0] = INV;
        int cnt = 0, res = INV;
        while (cnt < k) {
            auto [mv, id] = pq.top(); pq.pop();
            ++cnt;
            if (cnt == k) {
                res = mv;
                break;
            }
            int r = id / n, c = id % n;
            vector<int> dr = { 0, 1 }, dc = { 1, 0 };
            for (int i=0; i<2; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr>=n || nc>=n) continue;
                if (matrix[nr][nc] == INV) continue;
                pq.emplace(matrix[nr][nc], nr*n+nc);
                matrix[nr][nc] = INV;
            }
        }
        return res;
    }
};
