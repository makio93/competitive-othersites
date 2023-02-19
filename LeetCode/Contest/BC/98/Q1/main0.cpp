// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int n = s.length(), rval = 0, lval = INF;
        for (int i=0; i<=9; ++i) {
            string t = s;
            for (int j=0; j<n; ++j) if (t[j] == (char)('0'+i)) t[j] = '9';
            rval = max(rval, stoi(t));
        }
        for (int i=0; i<=9; ++i) {
            string t = s;
            for (int j=0; j<n; ++j) if (t[j] == (char)('0'+i)) t[j] = '0';
            lval = min(lval, stoi(t));
        }
        return rval - lval;
    }
};
