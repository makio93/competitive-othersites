// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        for (int val : { 0, h }) horizontalCuts.push_back(val);
        for (int val : { 0, w }) verticalCuts.push_back(val);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hm = 0, wm = 0, hi = horizontalCuts.size(), wi = verticalCuts.size();
        for (int i=0; i<hi-1; ++i) hm = max(hm, horizontalCuts[i+1]-horizontalCuts[i]);
        for (int i=0; i<wi-1; ++i) wm = max(wm, verticalCuts[i+1]-verticalCuts[i]);
        return (int)((ll)hm * wm % mod);
    }
};
