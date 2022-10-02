// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll minimumMoney(vector<vector<int>>& transactions) {
        int n = transactions.size();
        ll sum = 0;
        int mval = 0;
        for (auto& vi : transactions) {
            sum += max(0, vi[0]-vi[1]);
            mval = max(mval, min(vi[0], vi[1]));
        }
        return sum + mval;
    }
};
