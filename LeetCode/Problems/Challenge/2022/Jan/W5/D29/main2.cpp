#include <bits/stdc++.h>
using namespace std;

// 解説AC2

class Solution {
    int maxMidArea(vector<int>& hs, int li, int ri, int mi) {
        if (ri-li<1 || mi<li || mi>=ri) return 0;
        int si = mi, ti = mi+1, hval = hs[si], res = hval;
        while (si>li || ti<ri) {
            if (si-1 < li) ++ti;
            else if (ti+1 > ri) --si;
            else {
                if (hs[si-1] >= hs[ti]) --si;
                else ++ti;
            }
            hval = min({ hval, hs[si], hs[ti-1] });
            res = max(res, hval*(ti-si));
        }
        return res;
    }
    int maxArea(vector<int>& hs, int li, int ri) {
        if (ri-li <= 0) return 0;
        else if (ri-li == 1) return hs[li];
        else {
            int mi = li + (ri-li) / 2;
            return max({ maxArea(hs,li,mi), maxArea(hs,mi,ri), maxMidArea(hs,li,ri,mi) });
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        return maxArea(heights, 0, n);
    }
};
