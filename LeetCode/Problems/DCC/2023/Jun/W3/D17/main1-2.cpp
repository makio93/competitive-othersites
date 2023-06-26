// 解説AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        sort(arr2.begin(), arr2.end());
        map<int, int> dp;
        dp[-1] = 0;
        for (int i=0; i<n; ++i) {
            map<int, int> ndp;
            for (const auto& pi : dp) {
                if (arr1[i] > pi.first) {
                    if (ndp.find(arr1[i]) == ndp.end()) ndp[arr1[i]] = pi.second;
                    else ndp[arr1[i]] = min(ndp[arr1[i]], pi.second);
                }
                int ri = upper_bound(arr2.begin(), arr2.end(), pi.first) - arr2.begin();
                if (ri < m) {
                    if (ndp.find(arr2[ri]) == ndp.end()) ndp[arr2[ri]] = pi.second + 1;
                    else ndp[arr2[ri]] = min(ndp[arr2[ri]], pi.second + 1);
                }
            }
            swap(ndp, dp);
        }
        int res = INF;
        for (const auto& pi : dp) res = min(res, pi.second);
        if (res == INF) return -1;
        else return res;
    }
};
