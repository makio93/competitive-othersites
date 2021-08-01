#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        long long res = 0;
        vector<long long> sum(n+1);
        for (int i=0; i<n; ++i) sum[i+1] = sum[i] + height[i];
        map<int, int> choosed;
        choosed[-1] = choosed[n] = 0;
        vector<pair<int, int>> bar(n);
        for (int i=0; i<n; ++i) bar[i] = { height[i], i };
        sort(bar.rbegin(), bar.rend());
        for (int i=0; i<n; ++i) if (choosed.find(bar[i].second) == choosed.end()) {
            auto ritr = choosed.lower_bound(bar[i].second), litr = prev(ritr);
            int rh = min(bar[i].first, ritr->second), lh = min(bar[i].first, litr->second);
            choosed[bar[i].second] = bar[i].first;
            if (ritr->first>=0 && ritr->first<n) {
                for (int j=bar[i].second+1; j<ritr->first; ++j) {
                    res += rh - height[j];
                    choosed[j] = rh;
                }
            }
            if (litr->first>=0 && litr->first<n) {
                for (int j=litr->first+1; j<bar[i].second; ++j) {
                    res += lh - height[j];
                    choosed[j] = lh;
                }
            }
        }
        return (int)res;
    }
};
