#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), sum = 0;
        for (int i=0; i<m; ++i) sum += rolls[i];
        int sub = mean * (m+n) - sum, q = sub / n, r = sub % n;
        if (sub<n || sub>n*6) return vector<int>(0);
        vector<int> res(r, q+1), add(n-r, q);
        res.insert(res.end(), add.begin(), add.end());
        return res;
    }
};
