// 

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
    int calc(vector<int>& bc, int d) {
        if (d == 0) return (bc[d] > 0) ? 1 : 0;
        if (bc[d] > 1) return (1<<(d+1)) - 1;
        else if (bc[d] == 1) return (1<<d) + calc(bc, d-1);
        else return calc(bc, d-1);
    }
public:
    int maximalRating(vector<int> x) {
        int n = x.size();
        vector<int> bcnt(30);
        rep(i, n) rep(j, 30) if ((x[i]>>j)&1) bcnt[j]++;
        int mval = -1;
        repr(j, 30) if (bcnt[j] > 0) {
            mval = j;
            break;
        }
        if (mval == -1) return 0;
        else return calc(bcnt, mval);
    }
};
