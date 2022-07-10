// 本番WA

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
        if (N < R*3) {
            if (N%3 == 0) {
                rep(i, N/3) { res.push_back(1); res.push_back(2); }
            }
            else if (N%3 == 1) {
                if (N == 1) res.push_back(1);
                else {
                    res.push_back(1);
                    res.push_back(3);
                    rep(i, N/3-1) { res.push_back(1); res.push_back(2); }
                }
            }
            else if (N%3 == 2) {
                rep(i, 2) { res.push_back(1); res.push_back(3); }
                rep(i, N/3-2) { res.push_back(1); res.push_back(2); }
            }
        }
        else if (N == R*(C+2)+1) {
            res.push_back(1);
            res.push_back(C);
            rep(i, R-1) { res.push_back(1); res.push_back(C+1); }
            res.push_back(2);
        }
        else if (N <= R*(C+2)) {
            int p = N / R, q = N % R;
            rep(i, q) { res.push_back(1); res.push_back(p); }
            rep(i, R-q) { res.push_back(1); res.push_back(p-1); }
        }
        else {
            rep(i, R) { res.push_back(1); res.push_back(C+1); }
            int s = N - R*(C+2);
            vector<int> tmp;
            rep3r(i, 2, C+2) {
                if (s == 0) break;
                if (s >= i) {
                    if (s == i+1) {
                        tmp.push_back(2);
                        tmp.push_back(i-1);
                        s = 0;
                    }
                    else {
                        tmp.push_back(i);
                        s -= i;
                    }
                }
            }
            sort(all(tmp));
            for (int ti : tmp) res.push_back(ti);
        }
        return res;
    }
};
