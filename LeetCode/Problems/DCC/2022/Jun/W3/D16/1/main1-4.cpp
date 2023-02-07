// 学習1回目,解説AC4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ts;
        ts.push_back('|');
        for (int i=0; i<n; ++i) {
            ts.push_back(s[i]);
            ts.push_back('|');
        }
        vector<int> rvals(n*2+1);
        int cen = 0, rad = 0;
        while (cen < n*2+1) {
            while (cen-rad-1>=0 && cen+rad+1<n*2+1 && ts[cen-rad-1]==ts[cen+rad+1]) ++rad;
            rvals[cen] = rad;
            int pcen = cen, prad = rad;
            ++cen; rad = 0;
            while (cen <= pcen+prad) {
                int lcen = pcen - (cen-pcen), radmx = (pcen+prad) - cen;
                if (rvals[lcen] < radmx) {
                    rvals[cen] = rvals[lcen];
                    ++cen;
                }
                else if (rvals[lcen] > radmx) {
                    rvals[cen] = radmx;
                    ++cen;
                }
                else {
                    rad = rvals[lcen];
                    break;
                }
            }
        }
        pair<int, int> mval = { 0, 0 };
        for (int i=0; i<n*2+1; ++i) if (rvals[i] > 0) mval = max(mval, { rvals[i], -((i-(rvals[i]-1)-1)/2) });
        return s.substr(-mval.second, mval.first);
    }
};
