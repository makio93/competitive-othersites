// TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class FiringEmployees {
    int dfs(vector<vector<int>>& g, vector<int>& vals, int vi=0, int pi=-1) {
        int val = vals[vi];
        for (int ti : g[vi]) if (ti != pi) val += max(0, dfs(g, vals, ti, vi));
        return val;
    }
public:
    int fire(vector<int> manager, vector<int> salary, vector<int> productivity) {
        int n = manager.size();
        vector<int> vals(n+1);
        rep(i, n) vals[i+1] = productivity[i] - salary[i];
        vector<vector<int>> g(n+1);
        rep(i, n) g[manager[i]].push_back(i+1);
        return dfs(g, vals);
    }
};
