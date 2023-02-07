// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for (char ci : n) res = max(res, ci-'0');
        return res;
    }
};
