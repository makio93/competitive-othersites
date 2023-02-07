#include <bits/stdc++.h>
using namespace std;

// 自力AC,ヒントあり,元の解法で,static,vector<int>,良い結果

static vector<int> memo((int)(1e5)+5, -1);
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
        return (grundy(n) == 1);
    }
};
