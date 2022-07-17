// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, multiset<int>> slst;
        for (int& val : nums) {
            int tval = val, sum = 0;
            while (tval) {
                sum += tval % 10;
                tval /= 10;
            }
            slst[sum].insert(val);
        }
        int res = -1;
        for (auto& pi : slst) if ((int)(pi.second.size()) >= 2) {
            res = max(res, *pi.second.rbegin()+*next(pi.second.rbegin()));
        }
        return res;
    }
};
