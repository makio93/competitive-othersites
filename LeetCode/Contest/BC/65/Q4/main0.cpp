#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

// 本番WA

using ll = long long;
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        mcf_graph<int, int> g(n+m+2);
        for (int i=0; i<m; ++i) {
            int di = upper_bound(tasks.begin(), tasks.end(), workers[i]) - tasks.begin() - 1;
            if (di >= 0) g.add_edge(i, m+di, 1, 0);
            int di2 = upper_bound(tasks.begin(), tasks.end(), workers[i]+strength) - tasks.begin() - 1;
            if (di2 >= 0) for (int j=di2; j>di; --j) g.add_edge(i, m+j, 1, 1);
        }
        for (int i=0; i<m; ++i) g.add_edge(n+m, i, 1, 0);
        for (int i=m; i<m+n; ++i) g.add_edge(i, m+n+1, 1, 0);
        auto sl = g.slope(m+n, m+n+1);
        int res = 0;
        for (auto pi : sl) if (pi.second <= pills) res = max(res, pi.first);
        return res;
    }
};
