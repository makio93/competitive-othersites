// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        bool update = true;
        int rcnt = 0;
        while (update) {
            update = false;
            int i = rcnt % 2 == 0 ? 0 : n-1, r = rcnt % 2 == 0 ? 1 : -1;
            while (i>=0 && i<n) {
                if (i-1>=0 && ratings[i]>ratings[i-1] && candies[i]<=candies[i-1]) {
                    candies[i] = candies[i-1] + 1;
                    update = true;
                }
                if (i+1<n && ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]) {
                    candies[i] = candies[i+1] + 1;
                    update = true;
                }
                i += r;
            }
            ++rcnt;
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
