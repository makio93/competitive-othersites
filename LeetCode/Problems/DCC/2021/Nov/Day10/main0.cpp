#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), stock = -1, res = 0;
        for (int i=0; i<n; ++i) {
            if (i+1 < n) {
                if (prices[i+1]-prices[i]>=0 && stock==-1) stock = prices[i];
                else if (prices[i+1]-prices[i]<0 && stock!=-1) {
                    res += prices[i] - stock;
                    stock = -1;
                }
            }
            else if (stock != -1) res += prices[i] - stock;
        }
        return res;
    }
};
