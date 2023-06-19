// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size(), res = 0, val = 0;
        for (int i=0; i<n; ++i) {
            val += gain[i];
            res = max(res, val);
        }
        return res;
    }
};
