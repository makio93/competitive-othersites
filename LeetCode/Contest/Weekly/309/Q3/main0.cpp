// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bcnt(30);
        int res = 0, li = -1;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<30; ++j) if ((nums[i]>>j)&1) bcnt[j]++;
            while (*max_element(bcnt.begin(), bcnt.end()) >= 2) {
                ++li;
                for (int j=0; j<30; ++j) if ((nums[li]>>j)&1) bcnt[j]--;
            }
            res = max(res, i-li);
        }
        return res;
    }
};
