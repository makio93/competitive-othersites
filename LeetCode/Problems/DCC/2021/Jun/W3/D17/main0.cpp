#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ll = long long;
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        vector<pair<int, int>> vals(n);
        for (int i=0; i<n; ++i) vals[i] = { nums[i], i };
        sort(vals.rbegin(), vals.rend());
        int id1 = -1, id2 = -1;
        ll cnt1 = 0, cnt2 = 0;
        set<int> ids;
        for (id1=0; id1<n&&vals[id1].first>right; ++id1) ids.insert(vals[id1].second);
        ids.insert(-1);
        ids.insert(n);
        for (auto itr=ids.begin(); itr!=ids.end(); ++itr) if (*itr != n) {
            int di = *next(itr) - *itr - 1;
            cnt1 += (ll)di * (di+1) / 2;
        }
        for (id2=id1; id2<n&&vals[id2].first>=left; ++id2) ids.insert(vals[id2].second);
        for (auto itr=ids.begin(); itr!=ids.end(); ++itr) if (*itr != n) {
            int di = *next(itr) - *itr - 1;
            cnt2 += (ll)di * (di+1) / 2;
        }
        return (int)(cnt1 - cnt2);
    }
};
