// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const string tar = "+-";
class MaximumRange {
public:
    int findMax(string s) {
        int n = s.length();
        vector<vector<int>> lcnt(n+1, vector<int>(2)), rcnt(n+1, vector<int>(2));
        rep(i, n) {
            rep(j, 2) lcnt[i+1][j] += lcnt[i][j];
            lcnt[i+1][find(all(tar),s[i])-tar.begin()]++;
        }
        repr(i, n) {
            rep(j, 2) rcnt[i][j] += rcnt[i+1][j];
            rcnt[i][find(all(tar),s[i])-tar.begin()]++;
        }
        int res = 0;
        rep(i, n) rep(j, 2) res = max(res, abs(lcnt[i][j]-rcnt[i][1-j]));
        return res;
    }
};
