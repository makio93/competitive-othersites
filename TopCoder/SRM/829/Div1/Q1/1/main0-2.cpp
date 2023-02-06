// 復習1回目,自力AC

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
        if (N <= 3) res.push_back(N);
        else if (N == 4) res.push_back(1), res.push_back(3);
        else if (N == 5) res.push_back(2), res.push_back(3);
        else if (N <= 2*(C+2)) {
            int rval = N - 6, aval = min(rval, C-1), bval = rval - aval;
            res.push_back(1), res.push_back(2+bval);
            res.push_back(1), res.push_back(2+aval);
        } 
        else if (N <= R*(C+2)) {
            int aval = N / (C+2), bval = N % (C+2);
            if (bval == 1) {
                res.push_back(1), res.push_back(2);
                rep(i, 2) res.push_back(1), res.push_back(C);
                rep(i, aval-2) res.push_back(1), res.push_back(C+1);
            }
            else if (bval == 2) {
                res.push_back(1), res.push_back(2);
                res.push_back(1), res.push_back(C);
                rep(i, aval-1) res.push_back(1), res.push_back(C+1);
            }
            else {
                if (bval != 0) res.push_back(1), res.push_back(bval-1);
                rep(i, aval) res.push_back(1), res.push_back(C+1);
            }
        }
        else {
            int rval = N - (C+3) * C / 2, aval = rval / (C+2), bval = rval % (C+2);
            if (bval == 1) {
                res.push_back(1), res.push_back(2);
                rep(i, 2) res.push_back(1), res.push_back(C);
                rep(i, aval-2) res.push_back(1), res.push_back(C+1);
            }
            else if (bval == 2) {
                res.push_back(1), res.push_back(2);
                res.push_back(1), res.push_back(C);
                rep(i, aval-1) res.push_back(1), res.push_back(C+1);
            }
            else {
                if (bval != 0) res.push_back(1), res.push_back(bval-1);
                rep(i, aval) res.push_back(1), res.push_back(C+1);
            }
            rep3(i, 2, C+2) res.push_back(i);
        }
        return res;
    }
};
