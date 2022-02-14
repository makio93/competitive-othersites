#include <bits/stdc++.h>
using namespace std;

// 本番WA1

class Solution {
    int n, slen;
    vector<vector<pair<int, int>>> vlst;
    vector<int> ids;
    unordered_set<int> useds;
    int calc(int d, int val=0) {
        if ((int)(useds.size()) == n) return val;
        else if ((int)(useds.size())>n || ((int)(useds.size())<n&&d<=0)) return -1;
        else {
            int res = calc(d-1, val), id = 0, add = 0;
            vector<int> taken;
            for (int i=1; i<=2; ++i) {
                while (useds.find(vlst[d-1][id].second) != useds.end()) ++id;
                add += vlst[d-1][id].first;
                useds.insert(vlst[d-1][id].second);
                taken.push_back(vlst[d-1][id].second);
                int rval = calc(d-1, val+add);
                if (rval != -1) res = max(res, rval);
            }
            for (int ti : taken) useds.erase(ti);
            return res;
        }
    }
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        n = nums.size(); slen = numSlots;
        vlst = vector<vector<pair<int, int>>>(slen);
        for (int i=1; i<=slen; ++i) {
            for (int j=0; j<n; ++j) vlst[i-1].emplace_back((i&(nums[j])), j);
            sort(vlst[i-1].rbegin(), vlst[i-1].rend());
        }
        ids = vector<int>(slen);
        return calc(slen);
    }
};
