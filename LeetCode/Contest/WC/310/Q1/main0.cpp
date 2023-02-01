// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ncnt;
        for (int i=0; i<n; ++i) if (nums[i]%2 == 0) ncnt[nums[i]]++;
        pair<int, int> mval = { -1, -1 };
        for (auto pi : ncnt) mval = max(mval, { pi.second, -pi.first });
        int res = (mval.first == -1) ? -1 : -mval.second;
        return res;
    }
};
