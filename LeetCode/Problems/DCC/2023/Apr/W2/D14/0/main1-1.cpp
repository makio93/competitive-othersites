// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int calc(string& s, vector<vector<int>>& memo, int li, int ri) {
        if (memo[li][ri] != -1) return memo[li][ri];
        if (li > ri) return memo[li][ri] = 0;
        if (li == ri) return memo[li][ri] = 1;
        if (s[li] == s[ri]) return memo[li][ri] = calc(s, memo, li+1, ri-1) + 2;
        else return memo[li][ri] = max(calc(s, memo, li, ri-1), calc(s, memo, li+1, ri));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return calc(s, memo, 0, n-1);
    }
};
