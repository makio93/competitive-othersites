// 終了後実装

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class MatchingPatterns {
public:
    string solve(int N, vector<int> L, vector<string> patterns) {
        int n = N, m = patterns.size();
        unordered_map<int, set<pair<int, int>>> ccnt;
        int slen = 0;
        rep(i, m) {
            int len = patterns[i].length();
            vector<pair<int, int>> plst;
            rep(j, len) {
                if (isupper(patterns[i][j])) rep(i2, L[patterns[i][j]-'A']) plst.emplace_back(patterns[i][j]-'A', i2);
                else plst.emplace_back(N, patterns[i][j]-'a');
            }
            int len2 = plst.size();
            rep(j, len2) ccnt[j].insert(plst[j]);
            if (i != 0) { if (slen != len2) return string(""); }
            else slen = len2;
        }
        vector<vector<int>> checks(n);
        rep(i, n) checks[i].assign(L[i], -1);
        string res(slen, '.');
        rep(i, slen) {
            int tval = -1;
            for (auto pi : ccnt[i]) if (pi.first == N) {
                if (tval != -1) return string("");
                tval = pi.second;
            }
            if (tval == -1) continue;
            res[i] = (char)(tval+'a');
            for (auto pi : ccnt[i]) if (pi.first != N) {
                if (checks[pi.first][pi.second]!=-1 && checks[pi.first][pi.second]!=tval) return string("");
                checks[pi.first][pi.second] = tval;
            }
        }
        rep(i, slen) if (res[i] == '.') {
            int tval = -1;
            for (auto pi : ccnt[i]) if (checks[pi.first][pi.second] != -1) {
                if (tval == -1) tval = checks[pi.first][pi.second];
                else if (tval != checks[pi.first][pi.second]) return string("");
            }
            if (tval == -1) tval = 0;
            res[i] = (char)(tval+'a');
            for (auto pi : ccnt[i]) checks[pi.first][pi.second] = tval;
        }
        return res;
    }
};
