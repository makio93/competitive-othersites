#include <bits/stdc++.h>
using namespace std;

// 自力TLE

vector<int> memo((int)(1e5), -1);
class Solution {
    int grundy(int n) {
        if (memo[n] != -1) return memo[n];
        if (n == 0) return memo[n] = 0;
        else {
            int rval = (int)round(floor(sqrt(n)));
            if (rval*rval == n) return memo[n] = 1;
            unordered_set<int> vals;
            for (int i=1; i*i<=n; ++i) vals.insert(grundy(n-i*i));
            int res = 0;
            while (vals.find(res) != vals.end()) ++res;
            return memo[n] = res;
        }
    }
public:
    bool winnerSquareGame(int n) {
        return (grundy(n) != 0);
    }
};
