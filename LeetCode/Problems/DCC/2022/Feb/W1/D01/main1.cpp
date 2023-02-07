#include <bits/stdc++.h>
using namespace std;

// 解説AC,別解,"Kadane's Algorithm"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), sub = 0, res = 0;
        for (int i=0; i<n-1; ++i) {
            sub = max(0, sub+prices[i+1]-prices[i]);
            res = max(res, sub);
        }
        return res;
    }
};
