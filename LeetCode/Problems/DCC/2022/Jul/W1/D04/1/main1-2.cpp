// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ltor(n, 1), rtol(n, 1);
        for (int i=1; i<n; ++i) if (ratings[i] > ratings[i-1]) ltor[i] = ltor[i-1] + 1;
        for (int i=n-2; i>=0; --i) if (ratings[i] > ratings[i+1]) rtol[i] = rtol[i+1] + 1;
        int res = 0;
        for (int i=0; i<n; ++i) res += max(ltor[i], rtol[i]);
        return res;
    }
};
