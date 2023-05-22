// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> vcnt;
        for (int i=0; i<n; ++i) vcnt[nums[i]]++;
        int m = 1;
        while (m*m <= n*2) ++m;
        vector<vector<int>> vlst(m);
        for (const auto& pi : vcnt) vlst[pi.second-1].push_back(pi.first);
        vector<int> res;
        for (int i=m-1; i>=0; --i) {
            for (const int& vi : vlst[i]) {
                if ((int)(res.size()) >= k) break;
                res.push_back(vi);
            }
            if ((int)(res.size()) >= k) break;
        }
        return res;
    }
};
