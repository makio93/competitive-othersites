// バチャ本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class LinearSignals {
public:
    int maxSignals(string towers, int maxDist) {
        int n = towers.length();
        vector<int> sum(n+1);
        rep(i, n) sum[i+1] = sum[i] + (towers[i]=='X' ? 1 : 0);
        int res = 0;
        rep3(i, 1, n+1) res = max(res, (sum[i]-sum[max(0,i-maxDist-1)])+(sum[min(n,i+maxDist)]-sum[i]));
        return res;
    }
};
