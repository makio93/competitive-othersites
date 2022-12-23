// 解説AC4,O(n)解

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        pair<int, int> mval = { 0, -1 };
        string ts = "|";
        for (int i=0; i<n; ++i) ts += string("") + s[i] + '|';
        int m = ts.length();
        vector<int> rvals(m);
        int cid = 0, rval = 0;
        while (cid < m) {
            while (cid-rval-1>=0 && cid+rval+1<m && ts[cid-rval-1]==ts[cid+rval+1]) ++rval;
            rvals[cid] = rval;
            mval = max(mval, { rvals[cid], -cid });
            int pid = cid, pval = rval;
            ++cid; rval = 0;
            while (cid <= pid+pval) {
                int aval = rvals[pid-(cid-pid)], bval = pid + pval - cid;
                if (aval != bval) {
                    rvals[cid] = min(aval, bval);
                    mval = max(mval, { rvals[cid], -cid });
                    ++cid;
                }
                else {
                    rval = aval;
                    break;
                }
            }
        }
        int li = (-mval.second - mval.first) / 2, len = (mval.first*2 + 1) / 2;
        return s.substr(li, len);
    }
};
