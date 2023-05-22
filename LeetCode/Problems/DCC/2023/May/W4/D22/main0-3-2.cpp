// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> vcnt;
        for (int i=0; i<n; ++i) vcnt[nums[i]]++;
        vector<pair<int, int>> vlst;
        vlst.reserve(n);
        for (const auto& pi : vcnt) vlst.emplace_back(pi.second, pi.first);
        nth_element(vlst.begin(), vlst.begin()+k, vlst.end(), greater<pair<int, int>>());
        vector<int> res;
        for (int i=0; i<k; ++i) res.push_back(vlst[i].second);
        return res;
    }
};
