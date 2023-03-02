// 学習3回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class TopXorer {
public:
    int maximalRating(vector<int> x) {
        int n = x.size(), res = 0;
        vector<int> bcnt(30);
        rep(i, n) rep(j, 30) if (x[i]&(1<<j)) bcnt[j]++;
        repr(i, 30) {
            if (bcnt[i] >= 1) res += 1 << i;
            if (bcnt[i] >= 2) {
                res += (1<<i) - 1;
                break;
            }
        }
        return res;
    }
};
