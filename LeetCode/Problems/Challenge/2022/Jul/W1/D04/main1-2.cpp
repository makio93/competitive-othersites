// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> lvals(n, 1), rvals(n, 1);
        for (int i=1; i<n; ++i) if (ratings[i] > ratings[i-1]) lvals[i] = lvals[i-1] + 1;
        for (int i=n-2; i>=0; --i) if (ratings[i] > ratings[i+1]) rvals[i] = rvals[i+1] + 1;
        int res = 0;
        for (int i=0; i<n; ++i) res += max(lvals[i], rvals[i]);
        return res;
    }
};
