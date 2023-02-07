// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.front().size(), ri = n;
        for (int i=0; i<m; ++i) {
            int id = lower_bound(matrix[i].begin(), matrix[i].begin()+ri, target) - matrix[i].begin();
            if (id<ri && matrix[i][id]==target) return true;
            ri = id;
            if (ri == 0) break;
        }
        return false;
    }
};
