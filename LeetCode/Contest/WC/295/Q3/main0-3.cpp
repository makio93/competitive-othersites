// 本番WA2

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int calc(vector<int>& nums, int li, int ri) {
        if (ri-li <= 1) return 0;
        int res = 0;
        int nli = li;
        while (nli < ri) {
            int nri = nli + 1;
            while (nri<ri && nums[nri]<nums[nli]) ++nri;
            if (li==nli && ri==nri) return 1;
            res = max(res, calc(nums, nli+1, nri));
            nli = nri;
        }
        return res + 1;
    }
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        return calc(nums, 0, n);
    }
};
