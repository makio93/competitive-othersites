#include <bits/stdc++.h>
using namespace std;

// 自力AC

const long long mod = (long long)(1e9) + 7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int n = horizontalCuts.size(), m = verticalCuts.size();
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hval = horizontalCuts[0], vval = verticalCuts[0];
        for (int i=1; i<n; ++i) hval = max(hval, horizontalCuts[i]-horizontalCuts[i-1]);
        hval = max(hval, h-horizontalCuts[n-1]);
        for (int i=1; i<m; ++i) vval = max(vval, verticalCuts[i]-verticalCuts[i-1]);
        vval = max(vval, w-verticalCuts[m-1]);
        return (int)((long long)hval * vval % mod);
    }
};
