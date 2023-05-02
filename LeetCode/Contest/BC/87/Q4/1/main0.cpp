// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        int n = transactions.size(), mval = 0;
        ll sum = 0, res = 0;
        for (int i=0; i<n; ++i) {
            if (transactions[i][1]-transactions[i][0] <= 0) sum += transactions[i][1] - transactions[i][0];
            else mval = max(mval, transactions[i][0]);
        }
        res = sum - mval;
        for (int i=0; i<n; ++i) if (transactions[i][1]-transactions[i][0] <= 0) {
            res = min(res, sum-(transactions[i][1]-transactions[i][0])-transactions[i][0]);
        }
        return -res;
    }
};
