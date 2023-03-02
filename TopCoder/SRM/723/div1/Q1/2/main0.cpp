// 復習2回目,解説AC

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
        int n = x.size(), res = 0;
        repr(i, 30) {
            bool exist = false;
            rep(j, n) if ((x[j]>>i)&1) {
                if (!exist) {
                    res += 1<<i;
                    x[j] ^= 1<<i;
                    exist = true;
                }
                else x[j] = (1<<i) - 1;
            }
        }
        return res;
    }
};
