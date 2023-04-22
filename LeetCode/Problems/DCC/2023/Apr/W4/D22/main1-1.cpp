// 解説AC1(メモ化再帰)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string rs(s.rbegin(), s.rend());
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        auto calc = [&](auto& calc, int i1, int i2) -> int {
            if (memo[i1][i2] != -1) return memo[i1][i2];
            if (i1==0 || i2==0) return memo[i1][i2] = 0;
            else if (s[i1-1] == rs[i2-1]) return memo[i1][i2] = calc(calc, i1-1, i2-1) + 1;
            else return memo[i1][i2] = max(calc(calc, i1-1, i2), calc(calc, i1, i2-1));
        };
        return n - calc(calc, n, n);
    }
};
