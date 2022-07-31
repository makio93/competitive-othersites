// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class FiringEmployees {
public:
    int fire(vector<int> manager, vector<int> salary, vector<int> productivity) {
        int n = manager.size();
        vector<ll> dp(n+1);
        rep(i, n) dp[i+1] = productivity[i] - salary[i];
        rep3r(i, 1, n+1) {
            dp[i] = max(0LL, dp[i]);
            dp[manager[i-1]] += dp[i];
        }
        return dp[0];
    }
};
