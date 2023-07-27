// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        sort(batteries.begin(), batteries.end());
        long long extra = 0;
        for (int i=0; i<m-n; ++i) extra += batteries[i];
        for (int i=m-n+1; i<m; ++i) {
            if ((long long)(batteries[i]-batteries[i-1])*(i-(m-n)) <= extra) extra -= (long long)(batteries[i]-batteries[i-1])*(i-(m-n));
            else return batteries[i-1] + extra / (i-(m-n));
        }
        return batteries[m-1] + extra / n;
    }
};
