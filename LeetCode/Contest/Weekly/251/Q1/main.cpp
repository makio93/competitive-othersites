#include <bits/stdc++.h>
using namespace std;

class Solution {
    int calc(int val) {
        int res = 0;
        while (val > 0) {
            res += val % 10;
            val /= 10;
        }
        return res;
    }
public:
    int getLucky(string s, int k) {
        int n = s.length();
        int res = 0;
        for (int i=0; i<n; ++i) res += calc((int)(s[i]-'a'+1));
        for (int i=0; i<k-1; ++i) res = calc(res);
        return res;
    }
};
