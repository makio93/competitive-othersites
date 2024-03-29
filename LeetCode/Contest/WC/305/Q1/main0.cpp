// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size(), res = 0;
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            if (nums[j]-nums[i] > diff) break;
            if (nums[j]-nums[i] < diff) continue;
            for (int k=j+1; k<n; ++k) {
                if (nums[k]-nums[j] > diff) break;
                if (nums[k]-nums[j] < diff) continue;
                ++res;
            }
        }
        return res;
    }
};
