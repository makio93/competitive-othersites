// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    string to_nbase(int val, int nb) {
        string res;
        while (val) {
            res.push_back((char)('0'+val%nb));
            val /= nb;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool is_palind(string str) {
        int len = str.length(), li = 0, ri = len - 1;
        while (li < ri) {
            if (str[li] != str[ri]) return false;
            ++li; --ri;
        }
        return true;
    }
public:
    bool isStrictlyPalindromic(int n) {
        for (int i=2; i<=n-2; ++i) {
            string sval = to_nbase(n, i);
            if (!is_palind(sval)) return false;
        }
        return true;
    }
};
