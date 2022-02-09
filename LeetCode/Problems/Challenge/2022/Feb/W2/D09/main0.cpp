#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        if (k == 0) {
            unordered_map<int, int> vcnts;
            for (int i=0; i<n; ++i) vcnts[nums[i]]++;
            for (auto pi : vcnts) if (pi.second >= 2) ++res;
        }
        else {
            unordered_set<int> vals;
            for (int i=0; i<n; ++i) if (vals.find(nums[i]) == vals.end()) {
                if (vals.find(nums[i]+k) != vals.end()) ++res;
                if (vals.find(nums[i]-k) != vals.end()) ++res;
                vals.insert(nums[i]);
            }
        }
        return res;
    }
};
