// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n = nums.size(), m = divisors.size();
        pair<int, int> mval = { -1, -1 };
        for (int i=0; i<m; ++i) {
            int cnt = 0;
            for (int j=0; j<n; ++j) if (nums[j]%divisors[i] == 0) ++cnt;
            if (mval.first < cnt) mval = { cnt, divisors[i] };
            else if (mval.first==cnt && mval.second>divisors[i]) mval.second = divisors[i]; 
        }
        return mval.second;
    }
};
