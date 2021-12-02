// 自力で提出、ギリギリAC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix.front().size(), res = 0;
        vector<vector<long long>> sum(n+1, vector<long long>(m+1));
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + matrix[i][j];
        }
        for (int r1=0; r1<n; ++r1) for (int r2=r1+1; r2<=n; ++r2) {
            for (int c1=0; c1<m; ++c1) for (int c2=c1+1; c2<=m; ++c2) {
                if (sum[r2][c2]-sum[r1][c2]-sum[r2][c1]+sum[r1][c1] == (long long)target) ++res;
            }
        }
        return res;
    }
};

int main(){
    
    return 0;
}
