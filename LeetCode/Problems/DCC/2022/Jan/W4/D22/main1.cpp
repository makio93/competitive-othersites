#include <bits/stdc++.h>
using namespace std;

// 解説AC1,メモ化再帰

class Solution {
    unordered_map<int, bool> memo;
public:
    bool winnerSquareGame(int n) {
        if (memo.find(n) != memo.end()) return memo[n];
        if (n == 0) return memo[n] = false;
        else if (n == 1) return memo[n] = true;
        else {
            for (int i=1; i*i<=n; ++i) if (!winnerSquareGame(n-i*i)) return memo[n] = true;
            return memo[n] = false;
        }
    }
};
