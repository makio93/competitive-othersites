// 本番実装

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class SpireAttack {
public:
    int dealMostDamage(int N, vector<int> actions, vector<int> damage) {
        vector<vector<int>> dams(3);
        rep(i, N) dams[actions[i]-1].push_back(damage[i]);
        rep(i, 3) if (!dams[i].empty()) sort(dams[i].rbegin(), dams[i].rend());
        int res = 0;
        vector<vector<pair<int, int>>> vlst = { { { 1, 3 } }, { { 2, 1 }, { 1, 1 } }, { { 3, 1 } } };
        for (auto cm : vlst) {
            int sum = 0;
            for (auto p : cm) for (int i=0; i<p.second; ++i) if (i < (int)(dams[p.first-1].size())) sum += dams[p.first-1][i];
            res = max(res, sum);
        }
        return res;
    }
};
