#include <bits/stdc++.h>
using namespace std;

// 自力AC,ヒントあり,元の解法(メモ化再帰)

vector<int> memo;
class Solution {
    int grundy(int n) {
        if (memo[n] != -1) return memo[n];
        if (n == 0) return memo[n] = 0;
        else {
            for (int i=1; i*i<=n; ++i) if (grundy(n-i*i) == 0) return memo[n] = 1;
            return memo[n] = 0;
        }
    }
public:
    bool winnerSquareGame(int n) {
        memo = vector<int>(n+1, -1);
        return (grundy(n) == 1);
    }
};
