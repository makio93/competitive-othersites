// 本番

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class Delina {
public:
    double getProbability(int T, int G) {
        if (T == 1) return 1.0;
        vector<pair<long double, long double>> dp(1, make_pair(1.0, 0.0));
        rep(i, G+1) dp[0].first *= (T-1) / (long double)(20.0);
        dp[0].second = (long double)(1.0) - dp[0].first;
        long double res = dp[0].second;
        while (abs((long double)(1.0)-dp.back().second) > (long double)(1e-11)) {
            pair<long double, long double> nval = { dp.back().first, 0.0 };
            nval.first *= (T-1) / (long double)(20.0);
            nval.second = (long double)(1.0) - nval.first;
            dp.push_back(nval);
            res *= dp.back().second;
        }
        return (double)res;
    }
};
