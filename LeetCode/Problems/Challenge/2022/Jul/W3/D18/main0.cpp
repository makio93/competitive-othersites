// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.front().size(), res = 0;
        vector<vector<unordered_map<int, int>>> scnts(n, vector<unordered_map<int, int>>(n));
        vector<vector<int>> dsums(n, vector<int>(n));
        for (int i=0; i<n; ++i) for (int j=i; j<n; ++j) scnts[i][j][0]++;
        for (int di=0; di<m; ++di) for (int li=0; li<n; ++li) {
            int dsum = 0;
            for (int ri=li; ri<n; ++ri) {
                dsum += matrix[di][ri];
                dsums[li][ri] += dsum;
                int tval = dsums[li][ri] - target;
                if (scnts[li][ri].find(tval) != scnts[li][ri].end()) res += scnts[li][ri][tval];
                scnts[li][ri][dsums[li][ri]]++;
            }
        }
        return res;
    }
};
