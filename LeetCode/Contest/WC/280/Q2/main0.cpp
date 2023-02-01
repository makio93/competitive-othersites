#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        unordered_map<int, int> vcnt0, vcnt1;
        for (int i=0; i<n; i+=2) vcnt0[nums[i]]++;
        for (int i=1; i<n; i+=2) vcnt1[nums[i]]++;
        vector<pair<int, int>> vlst0, vlst1;
        for (auto pi : vcnt0) vlst0.emplace_back(pi.second, pi.first);
        for (auto pi : vcnt1) vlst1.emplace_back(pi.second, pi.first);
        vlst0.emplace_back(0, (int)(1e5)+1);
        vlst1.emplace_back(0, (int)(1e5)+2);
        sort(vlst0.rbegin(), vlst0.rend());
        sort(vlst1.rbegin(), vlst1.rend());
        int res = (int)(1e9);
        for (int i=0; i<2; ++i) for (int j=0; j<2; ++j) {
            if (vlst0[i].second == vlst1[j].second) continue;
            res = min(res, ((n+1)/2-vlst0[i].first)+(n/2-vlst1[j].first));
        }
        return res;
    }
};
