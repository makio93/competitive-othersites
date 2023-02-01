// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        if (k == n) {
            int mval = 0;
            for (int i=0; i<n; ++i) mval = max(mval, cookies[i]);
            return mval;
        }
        int res = INF;
        vector<int> tlst(k);
        auto dfs = [&](auto dfs, int di=0, int ri=0) -> void {
            if (di == n) {
                int val = 0;
                for (int i=0; i<k; ++i) val = max(val, tlst[i]);
                res = min(res, val);
                return;
            }
            for (int i=0; i<ri; ++i) {
                tlst[i] += cookies[di];
                dfs(dfs, di+1, ri);
                tlst[i] -= cookies[di];
            }
            if (ri < k) {
                tlst[ri] += cookies[di];
                dfs(dfs, di+1, ri+1);
                tlst[ri] -= cookies[di];
            }
        };
        dfs(dfs);
        return res;
    }
};
