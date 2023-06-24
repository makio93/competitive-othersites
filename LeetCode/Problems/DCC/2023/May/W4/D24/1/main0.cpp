// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vals(n);
        for (int i=0; i<n; ++i) vals[i] = { nums2[i], nums1[i] };
        sort(vals.rbegin(), vals.rend());
        for (int i=0; i<n; ++i) {
            nums1[i] = vals[i].second;
            nums2[i] = vals[i].first;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        ll val = 0, res = 0;
        for (int i=0; i<n; ++i) {
            val += nums1[i];
            pq.push(nums1[i]);
            if ((int)(pq.size()) > k) {
                val -= pq.top();
                pq.pop();
            }
            if ((int)(pq.size()) == k) res = max(res, val*nums2[i]);
        }
        return res;
    }
};
