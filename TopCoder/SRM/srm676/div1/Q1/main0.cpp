// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class WaterTank {
public:
    double minOutputRate(vector<int> t, vector<int> x, int C) {
        int n = t.size();
        double l = 0.0, r = 1e6;
        while (r-l >= 1e-7) {
            double c = (l + r) / 2.0, val = 0.0;
            bool ok = true;
            rep(i, n) {
                double ri = (double)(x[i]) - c, nval = max(0.0, val+(double)(t[i])*ri);
                if (nval > (double)C) {
                    ok = false;
                    break;
                }
                val = nval;
            }
            if (ok) r = c;
            else l = c;
        }
        return r;
    }
};
