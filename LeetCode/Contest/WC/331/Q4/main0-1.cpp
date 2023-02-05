// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        ll sum1 = accumulate(basket1.begin(), basket1.end(), 0LL), sum2 = accumulate(basket2.begin(), basket2.end(), 0LL);
        if (abs(sum1-sum2)%2 == 1) return -1;
        if (sum1 > sum2) {
            swap(basket1, basket2);
            swap(sum1, sum2);
        }
        sort(basket1.begin(), basket1.end());
        multiset<int> st2;
        for (int i=0; i<n; ++i) st2.insert(basket2[i]);
        ll sub = (sum2 - sum1) / 2, res = 0;
        for (int i=0; i<n; ++i) {
            auto itr = st2.upper_bound(basket1[i]+sub);
            if (itr == st2.begin()) continue;
            --itr;
            if (basket1[i] > *itr) continue;
            res += basket1[i];
            sub -= *itr - basket1[i];
            st2.erase(itr);
            if (sub == 0) break;
        }
        if (sub > 0) return -1;
        else return res;
    }
};
