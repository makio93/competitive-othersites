// 解説見て実装

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix.front().size();
        vector<vector<int>> rsum(n, vector<int>(m+1));
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) rsum[i][j+1] = rsum[i][j] + matrix[i][j];
        int res = 0;
        for (int i1=0; i1<m; ++i1) for (int i2=i1+1; i2<=m; ++i2) {
            unordered_map<int, int> scnt;
            int msum = 0;
            scnt[msum]++;
            for (int j=0; j<n; ++j) {
                msum += rsum[j][i2] - rsum[j][i1];
                if (scnt.find(msum-target) != scnt.end()) res += scnt[msum-target];
                scnt[msum]++;
            }
        }
        return res;
    }
};

int main(){
    
    return 0;
}
