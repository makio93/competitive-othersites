// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int m = arr2.size();
        vector<int> vlst;
        for (int i=0; i<n; ++i) vlst.push_back(arr1[i]);
        for (int i=0; i<m; ++i) vlst.push_back(arr2[i]);
        vlst.push_back(-1);
        sort(vlst.begin(), vlst.end());
        vlst.erase(unique(vlst.begin(), vlst.end()), vlst.end());
        for (int i=0; i<n; ++i) arr1[i] = lower_bound(vlst.begin(), vlst.end(), arr1[i]) - vlst.begin();
        for (int i=0; i<m; ++i) arr2[i] = lower_bound(vlst.begin(), vlst.end(), arr2[i]) - vlst.begin();
        int vlen = vlst.size();
        vector<int> dp(vlen, INF), ndp;
        dp[0] = 0;
        for (int i=0; i<n; ++i) {
            vector<int> tlst = arr2;
            tlst.push_back(arr1[i]);
            sort(tlst.begin(), tlst.end());
            tlst.erase(unique(tlst.begin(), tlst.end()), tlst.end());
            ndp.assign(vlen, INF);
            int tlen = tlst.size(), ti = 0, mval = INF;
            for (int j=0; j<vlen; ++j) {
                mval = min(mval, dp[j]);
                while (ti<tlen && tlst[ti]<=j) ++ti;
                if (ti >= tlen) break;
                if (mval == INF) continue;
                int cost = tlst[ti] == arr1[i] ? 0 : 1;
                ndp[tlst[ti]] = min(ndp[tlst[ti]], mval+cost);
            }
            swap(ndp, dp);
        }
        int res = INF;
        for (int i=0; i<vlen; ++i) res = min(res, dp[i]);
        return res >= INF ? -1 : res;
    }
};
