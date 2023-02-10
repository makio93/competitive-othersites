// 学習1回目,解説AC4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int pdif = nums[1] - nums[0], res = (pdif == 0) ? 1 : 2;
        for (int i=2; i<n; ++i) {
            int dif = nums[i] - nums[i-1];
            if ((dif>0&&pdif<=0) || (dif<0&&pdif>=0)) {
                ++res;
                pdif = dif;
            }
        }
        return res;
    }
};
