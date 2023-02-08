// 学習1回目,解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i=1; i<n; ++i) if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
        int res = candies[n-1];
        for (int i=n-2; i>=0; --i) {
            if (ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1]+1);
            res += candies[i];
        }
        return res;
    }
};
