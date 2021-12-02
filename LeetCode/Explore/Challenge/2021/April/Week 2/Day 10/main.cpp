#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m, n;
    vector<vector<int>> dist;
    int dfs(vector<vector<int>>& matrix, int v, int mode) {
        if (dist[mode][v] != -1) return dist[mode][v];
        else {
            dist[mode][v] = 0;
            const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            int y = v / n, x = v % n, res = 0;
            for (int i1=0; i1<4; ++i1) {
                int ny = y + dy[i1], nx = x + dx[i1];
                if (ny<0 || ny>=m || nx<0 || nx>=n) continue;
                if (mode==0 && matrix[ny][nx]<=matrix[y][x]) continue;
                if (mode==1 && matrix[ny][nx]>=matrix[y][x]) continue;
                res = max(res, dfs(matrix, ny*n+nx, mode));
            }
            dist[mode][v] = res + 1;
            return res + 1;
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(); n = matrix.front().size();
        dist = vector<vector<int>>(2, vector<int>(m*n, -1));
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            if (dist[0][i*n+j] == -1) dfs(matrix, i*n+j, 0);
            if (dist[1][i*n+j] == -1) dfs(matrix, i*n+j, 1);
        }
        int res = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res = max(res, dist[0][i*n+j]+dist[1][i*n+j]-1);
        return res;
    }
};

int main(){
    Solution cl;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) cin >> matrix[i][j];
    cout << cl.longestIncreasingPath(matrix) << endl;
    return 0;
}
