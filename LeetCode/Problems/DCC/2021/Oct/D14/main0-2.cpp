#include <bits/stdc++.h>
using namespace std;

// 自力AC2,メモ化再帰,効率が悪い

class Solution {
    unordered_map<int, int> memo;
    int calc(int val) {
        if (memo.find(val) != memo.end()) return memo[val];
        int rval = (int)sqrt(val);
        if (rval*rval == val) return memo[val] = 1;
        int res = (int)(1e9);
        for (int i=1; i*i<val; ++i) {
            res = min(res, calc(i*i)+calc(val-i*i));
            if (res <= 2) return (memo[val] = res);
        }
        return (memo[val] = res);
    }
public:
    int numSquares(int n) { return calc(n); }
};
