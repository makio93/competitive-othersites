#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    unordered_map<int, int> memo;
    bool check(int n) {
        bool pbit = false;
        while (n > 0) {
            if (n&1) {
                if (pbit) return true;
                else pbit = true;
            }
            else pbit = false;
            n >>= 1;
        }
        return false;
    }
    int calc(int n) {
        if (memo.find(n) != memo.end()) return memo[n];
        if (n == 0) return (memo[n] = 0);
        int res = (check(n) ? 1 : 0), tmp = n, sub = 1;
        while (tmp > 0) {
            if (tmp&sub) {
                tmp -= sub;
                if (check(tmp)) res += sub;
                else res += calc(sub-1);
            }
            sub <<= 1;
        }
        return (memo[n] = res);
    }
public:
    int findIntegers(int n) {
        return ((n+1) - calc(n));
    }
};
