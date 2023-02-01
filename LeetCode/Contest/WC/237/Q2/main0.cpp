#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int res = 0, sum = 0;
        for (int i=0; i<n; ++i) {
            if (sum+costs[i] <= coins) {
                ++res;
                sum += costs[i];
            }
            else break;
        }
        return res;
    }
};
