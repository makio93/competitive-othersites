// 復習1回目,自力,誤読

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
        int rval = (C+2) * (C+1) / 2;
        vector<int> res;
        if (N > rval) {
            int val = N - (rval - 1);
            int aval = val / (C+2), bval = val % (C+2);
            if (bval == 1) {
                res.push_back(2), res.push_back(1), res.push_back(C);
                rep(i, aval-1) { res.push_back(1), res.push_back(C+1); }
            }
            else {
                if (bval != 0) res.push_back(bval);
                rep(i, aval) { res.push_back(1), res.push_back(C+1); }
            }
            rep3(i, 2, C+2) res.push_back(i);
        }
        else if (N > C+2) {
            int aval = N / (C+2), bval = N % (C+2);
            if (bval == 1) {
                res.push_back(2), res.push_back(1), res.push_back(C);
                rep(i, aval-1) { res.push_back(1), res.push_back(C+1); }
            }
            else {
                if (bval != 0) res.push_back(bval);
                rep(i, aval) { res.push_back(1), res.push_back(C+1); }
            }
        }
        else {
            if (N == C+2) res.push_back(1), res.push_back(C+1);
            else res.push_back(N);
        }
        return res;
    }
};
