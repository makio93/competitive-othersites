// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> vcnt;
        for (int i=0; i<n; ++i) vcnt[nums[i]]++;
        vector<int> vlst;
        for (const auto& pi : vcnt) vlst.push_back(pi.first);
        function<int(int,int,int)> partial = [&](int li, int ri, int ci) {
            if (ri-li <= 1) return li;
            swap(vlst[ci], vlst[ri-1]);
            for (int i=li; i<ri-1; ++i) if (vcnt[vlst[i]] >= vcnt[vlst[ri-1]]) swap(vlst[i], vlst[li++]);
            swap(vlst[li], vlst[ri-1]);
            return li;
        };
        int lv = 0, rv = vlst.size();
        while (rv-lv > 1) {
            int cv = partial(lv, rv, (lv+rv)/2);
            if (cv < k) lv = cv;
            else rv = cv;
        }
        vlst.resize(k);
        return vlst;
    }
};
