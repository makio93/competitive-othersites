// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.front().size(), res = 0;
        for (int i=0; i<m; ++i) for (int j=1; j<n; ++j) matrix[i][j] += matrix[i][j-1];
        unordered_map<int, int> scnt;
        for (int i=0; i<n; ++i) for (int j=i; j<n; ++j) {
            int sum = 0;
            scnt = { { 0, 1 } };
            for (int k=0; k<m; ++k) {
                sum += matrix[k][j] - (i-1>=0 ? matrix[k][i-1] : 0);
                if (scnt.find(sum-target) != scnt.end()) res += scnt[sum-target];
                scnt[sum]++;
            }
        }
        return res;
    }
};
