#include <bits/stdc++.h>
using namespace std;

// 自力AC,ヒントあり,元の解法で,static,unordered_map,あまり良くない

static unordered_map<int, int> memo;
class Solution {
    int grundy(int n) {
        if (memo.find(n) != memo.end()) return memo[n];
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
