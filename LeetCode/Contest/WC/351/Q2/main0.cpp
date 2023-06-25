// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        ll val = num1;
        for (int i=1; i<=60; ++i) {
            val -= num2;
            if (val >= 0LL && __builtin_popcountll(val) <= i && i <= val) return i;
        }
        return -1;
    }
};
