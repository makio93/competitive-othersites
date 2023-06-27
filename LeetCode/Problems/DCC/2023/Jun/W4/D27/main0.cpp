// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        set<pair<int, int>> used;
        pq.emplace(nums1[0]+nums2[0], 0, 0);
        used.emplace(0, 0);
        vector<vector<int>> res;
        while ((int)(res.size()) < k && !pq.empty()) {
            auto [sum, i1, i2] = pq.top(); pq.pop();
            res.push_back({ nums1[i1], nums2[i2] });
            if (i1+1 < n && used.find({ i1+1, i2 }) == used.end()) {
                pq.emplace(nums1[i1+1]+nums2[i2], i1+1, i2);
                used.emplace(i1+1, i2);
            }
            if ((int)(res.size()) < k && i2+1 < m && used.find({ i1, i2+1 }) == used.end()) {
                pq.emplace(nums1[i1]+nums2[i2+1], i1, i2+1);
                used.emplace(i1, i2+1);
            }
        }
        return res;
    }
};
