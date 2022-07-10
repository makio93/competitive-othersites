// 本番後,解説確認後,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class SnookerScoring {
public:
    vector<int> scoreN(int N, int R, int C) {
        vector<int> res;
        if (N < 6) {
            if (N == 1) res.push_back(1);
            else if (N == 2) res.push_back(2);
            else {
                res.push_back(1);
                if (N == 3) res.push_back(2);
                else {
                    res.push_back(3);
                    if (N == 5) res.push_back(1);
                }
            }
        }
        else {
            vector<int> lst;
            rep3(i, 2, C+2) {
                if (N-6 < i) break;
                N -= i;
                lst.push_back(i);
            }
            if (N < R*3) {
                if (N%3 == 0) rep(i, N/3) { res.push_back(1); res.push_back(2); }
                else {
                    rep(i, N%3) { res.push_back(1); res.push_back(3); }
                    rep(i, N/3-N%3) { res.push_back(1); res.push_back(2); }
                }
            }
            else {
                int p = N / R, q = N % R;
                rep(i, q) { res.push_back(1); res.push_back(p); }
                rep(i, R-q) { res.push_back(1); res.push_back(p-1); }
            }
            if (!lst.empty()) for (int vi : lst) res.push_back(vi);
        }
        return res;
    }
};
