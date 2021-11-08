#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, int> memo;
    int f(int n) {
        if (memo.find(n) != memo.end()) return memo[n];
        if (n == 0) return (memo[n] = 1);
        int res = 0;
        for (int i=1; i<=n; ++i) res += f(i-1) * f(n-i);
        return (memo[n] = res);
    }
public:
    int numTrees(int n) {
        return f(n);
    }
};