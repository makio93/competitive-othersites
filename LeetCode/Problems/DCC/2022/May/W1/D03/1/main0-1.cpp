// 学習1回目,自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        auto cplst = nums;
        sort(cplst.begin(), cplst.end());
        if (cplst == nums) return 0;
        int li = n, ri = -1;
        for (int i=0; i<n; ++i) if (nums[i] != cplst[i]) li = min(li, i), ri = max(ri, i);
        return ri - li + 1;
    }
};
