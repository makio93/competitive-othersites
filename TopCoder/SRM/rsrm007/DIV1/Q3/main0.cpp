// バチャ本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
class PackageSizes {
public:
    int getMinimum(vector<int> sizes, int total) {
        int n = sizes.size();
        vector<int> dp(total+1, INF);
        dp[0] = 0;
        rep(i, n) rep3(j, sizes[i], total+1) dp[j] = min(dp[j], dp[j-sizes[i]]+1);
        return (dp[total] != INF) ? dp[total] : -1;
    }
};
