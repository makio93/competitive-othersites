#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> nlst(n);
        for (int i=0; i<n; ++i) nlst[i] = { efficiency[i], speed[i] };
        sort(nlst.rbegin(), nlst.rend());
        priority_queue<int, vector<int>, greater<int>> klst;
        ll ksum = 0, res = 0;
        for (int i=0; i<n; ++i) {
            if ((int)(klst.size()) < k) {
                ksum += nlst[i].second;
                klst.push(nlst[i].second);
            }
            else if (klst.top() < nlst[i].second) {
                ksum += nlst[i].second - klst.top();
                klst.pop(); klst.push(nlst[i].second);
            }
            res = max(res, ksum*nlst[i].first);
        }
        return (int)(res % mod);
    }
};
