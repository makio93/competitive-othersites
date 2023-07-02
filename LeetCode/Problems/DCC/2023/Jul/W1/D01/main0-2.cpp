// 自力AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        function<int(int,int,vector<int>&)> f = [&](int vi, int ri, vector<int>& vals) {
            if (vi == n) return *max_element(vals.begin(), vals.end());
            int rval = INF;
            for (int i=0; i <= min(ri+1, k-1); ++i) {
                vals[i] += cookies[vi];
                rval = min(rval, f(vi+1, max(ri, i), vals));
                vals[i] -= cookies[vi];
            }
            return rval;
        };
        vector<int> vals(k);
        return f(0, -1, vals);
    }
};
