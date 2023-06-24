// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vals(n);
        for (int i=0; i<n; ++i) vals[i] = { nums1[i], nums2[i] };
        sort(vals.begin(), vals.end(), [](auto& av, auto& bv) -> bool { return av.second > bv.second; });
        priority_queue<int, vector<int>, greater<int>> pq;
        ll res = 0, sum = 0;
        for (int i=0; i<n; ++i) {
            sum += vals[i].first;
            pq.push(vals[i].first);
            if ((int)(pq.size()) > k) sum -= pq.top(), pq.pop();
            if ((int)(pq.size()) == k) res = max(res, sum*vals[i].second);
        }
        return res;
    }
};
