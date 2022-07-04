// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> vals(n, 1);
        for (int i=0; i<n; ++i) if ((i-1<0||ratings[i-1]>=ratings[i]) && (i+1>=n||ratings[i+1]>=ratings[i])) {
            int nval = 1, id = i;
            while (id-1>=0 && ratings[id-1]>ratings[id]) {
                --id; ++nval;
                vals[id] = max(vals[id], nval);
            }
            nval = 1, id = i;
            while (id+1<n && ratings[id+1]>ratings[id]) {
                ++id; ++nval;
                vals[id] = max(vals[id], nval);
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) res += vals[i];
        return res;
    }
};
