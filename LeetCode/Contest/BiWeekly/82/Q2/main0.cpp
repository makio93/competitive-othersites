// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int n = buses.size(), m = passengers.size();
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        unordered_set<int> pvals;
        for (int pval : passengers) pvals.insert(pval);
        int mid = 0, res = 0;
        for (int i=0; i<n; ++i) {
            int cnt = 0;
            while (mid<m && cnt<capacity && passengers[mid]<=buses[i]) {
                if (pvals.find(passengers[mid]-1) == pvals.end()) res = max(res, passengers[mid]-1);
                ++cnt; ++mid;
            }
            if (cnt<capacity && pvals.find(buses[i])==pvals.end()) res = max(res, buses[i]);
        }
        return res;
    }
};
