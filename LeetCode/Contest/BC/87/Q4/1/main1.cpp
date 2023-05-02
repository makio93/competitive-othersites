// 学習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        int n = transactions.size(), mval = 0;
        ll sum = 0;
        for (int i=0; i<n; ++i) {
            mval = max(mval, min(transactions[i][0], transactions[i][1]));
            sum += max(0, transactions[i][0]-transactions[i][1]);
        }
        return sum + mval;
    }
};
