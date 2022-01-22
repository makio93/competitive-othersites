#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long aval = 0, bval = 0, hval = 0;
        for (int i=0; i<n; ++i) {
            hval += differences[i];
            aval = min(aval, hval);
            bval = max(bval, hval);
        }
        return (int)max(0LL, ((long long)upper-lower)-(bval-aval)+1);
    }
};
