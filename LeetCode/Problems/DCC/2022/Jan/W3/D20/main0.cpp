#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long sum = 0;
        for (int i=0; i<n; ++i) sum += piles[i];
        long long li = 0, ri = sum;
        while (ri-li > 1) {
            long long ci = ri - (ri-li) / 2, val = 0;
            for (int i=0; i<n; ++i) val += (piles[i]+ci-1) / ci;
            if (val <= h) ri = ci;
            else li = ci;
        }
        return (int)ri;
    }
};
