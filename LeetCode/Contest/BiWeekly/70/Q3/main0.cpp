#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<int>> rank;
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> que;
        vector<vector<int>> dist(m, vector<int>(n, (int)(1e9)));
        dist[start[0]][start[1]] = 0;
        que.emplace(0, grid[start[0]][start[1]], start[0], start[1]);
        while (!que.empty()) {
            auto [di, vi, ri, ci] = que.top(); que.pop();
            if (vi>=2 && vi>=pricing[0] && vi<=pricing[1]) rank.push_back(vector<int>({ri, ci}));
            int ndi = di + 1;
            const vector<int> dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };
            for (int i1=0; i1<4; ++i1) {
                int nr = ri + dr[i1], nc = ci + dc[i1];
                if (nr<0 || nr>=m || nc<0 || nc>=n || grid[nr][nc]==0 || dist[nr][nc]<=ndi) continue;
                dist[nr][nc] = ndi;
                que.emplace(ndi, grid[nr][nc], nr, nc);
            }
        }
        vector<vector<int>> res;
        for (vector<int> vi : rank) {
            res.push_back(vi);
            if ((int)(res.size()) == k) break;
        }
        return res;
    }
};
