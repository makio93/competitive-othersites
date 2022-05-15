// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<int> bcnt(24);
        for (int i=0; i<n; ++i) for (int j=0; j<24; ++j) bcnt[j] += ((candidates[i]>>j) & 1);
        int res = 0;
        for (int i=0; i<24; ++i) res = max(res, bcnt[i]);
        return res;
    }
};
