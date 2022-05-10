// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

class TopXorer {
public:
    int maximalRating(vector<int> x) {
        int n = x.size();
        vector<int> bcnt(30);
        rep(i, n) rep(j, 30) if ((x[i]>>j)&1) bcnt[j]++;
        int res = 0;
        repr(i, 30) {
            if (bcnt[i] >= 1) res |= (1<<i);
            if (bcnt[i] > 1) {
                res |= (1<<i) - 1;
                break;
            }
        }
        return res;
    }
};
