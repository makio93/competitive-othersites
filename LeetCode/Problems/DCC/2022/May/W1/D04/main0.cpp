// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> vcnt;
        for (int i=0; i<n; ++i) vcnt[nums[i]]++;
        for (auto& pi : vcnt) {
            if (pi.first<k-pi.first && vcnt.find(k-pi.first)!=vcnt.end()) res += min(pi.second, vcnt[k-pi.first]);
            if (pi.first == k-pi.first) res += pi.second / 2;
        }
        return res;
    }
};
