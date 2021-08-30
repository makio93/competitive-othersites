#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int len = ops.size();
        vector<int> mval = { m, n };
        for (int i=0; i<len; ++i) for (int j=0; j<2; ++j) mval[j] = min(mval[j], ops[i][j]);
        return mval[0] * mval[1];
    }
};
