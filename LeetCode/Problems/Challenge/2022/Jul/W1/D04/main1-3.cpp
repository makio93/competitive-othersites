// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> vals(n, 1);
        for (int i=1; i<n; ++i) if (ratings[i] > ratings[i-1]) vals[i] = vals[i-1] + 1;
        for (int i=n-2; i>=0; --i) if (ratings[i] > ratings[i+1]) vals[i] = max(vals[i], vals[i+1]+1);
        return accumulate(vals.begin(), vals.end(), 0);
    }
};
