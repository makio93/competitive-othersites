// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.front().size();
        if (matrix[0][0]>target || matrix[m-1][n-1]<target) return false;
        int ri = 0;
        int id = lower_bound(matrix[ri].begin(), matrix[ri].end(), target) - matrix[ri].begin();
        if (id == n) {
            --id;
            int ui = 0, di = m-1;
            while (di-ui > 0) {
                int ci = ui + (di-ui) / 2;
                if (matrix[ci][id] < target) ui = ci + 1;
                else di = ci;
            }
            ri = ui;
        }
        while (ri < m) {
            while (id>=0 && matrix[ri][id]>target) --id;
            if (id < 0) break;
            if (matrix[ri][id] == target) return true;
            ++ri;
        }
        return false;
    }
};
