// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), lval = matrix[0][0] - 1, rval = matrix[n-1][n-1];
        auto mcnt = [&](int val) -> int {
            int cid = n-1, rcnt = 0;
            for (int i=0; i<n; ++i) {
                while (cid>=0 && matrix[i][cid]>val) --cid;
                rcnt += cid + 1;
            }
            return rcnt;
        };
        while (rval-lval > 1) {
            int cval = rval - (rval-lval) / 2;
            if (mcnt(cval) >= k) rval = cval;
            else lval = cval;
        }
        return rval;
    }
};
