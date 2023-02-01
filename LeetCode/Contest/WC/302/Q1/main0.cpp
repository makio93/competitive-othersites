// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> ncnt(101);
        for (int val : nums) ncnt[val]++;
        vector<int> ans(2);
        for (int i=0; i<=100; ++i) {
            ans[0] += ncnt[i] / 2;
            ans[1] += ncnt[i] % 2;
        }
        return ans;
    }
};
