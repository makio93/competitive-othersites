#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    const vector<int> dy = { 0, 1, 0, -1 }, dx = { 1, 0, -1, 0 };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        vector<int> res;
        int y = 0, x = 0, d = 0;
        vector<vector<bool>> visited(n, vector<bool>(m));
        res.push_back(matrix[y][x]);
        visited[y][x] = true;
        for (int i=0; i<n*m-1; ++i) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny<0||ny>=n||nx<0||nx>=m||visited[ny][nx]) {
                d = (d+1) % 4;
                ny = y + dy[d]; nx = x + dx[d];
            }
            res.push_back(matrix[ny][nx]);
            visited[ny][nx] = true;
            y = ny; x = nx;
        }
        return res;
    }
};
