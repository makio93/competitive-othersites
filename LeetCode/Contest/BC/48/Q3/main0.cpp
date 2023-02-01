// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int sum = 0;
        for (int i=0; i<n; ++i) {
            if (coins[i] <= sum+1) sum += coins[i];
            else break;
        }
        return sum + 1;
    }
};
