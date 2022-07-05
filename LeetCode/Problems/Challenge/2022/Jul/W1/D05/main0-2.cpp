// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        for (int& val : nums) val += (int)(1e9);
        vector<vector<int>> vlst(10, vector<int>(n));
        int ten = 1;
        for (int i=0; i<10; ++i) {
            vector<int> ids(10);
            for (int& val : nums) {
                vlst[val/ten%10][ids[val/ten%10]] = val;
                ids[val/ten%10]++;
            }
            int id = 0;
            for (int j=0; j<10; ++j) for (int j2=0; j2<ids[j]; ++j2) {
                nums[id] = vlst[j][j2];
                ++id;
            }
            if (i < 9) ten *= 10;
        }
        int res = 0, cnt = 0;
        for (int i=0; i<n; ++i) {
            if (i-1>=0 && nums[i]==nums[i-1]+1) ++cnt;
            else if (i-1<0 || nums[i]!=nums[i-1]) cnt = 1;
            res = max(res, cnt);
        }
        return res;
    }
};
