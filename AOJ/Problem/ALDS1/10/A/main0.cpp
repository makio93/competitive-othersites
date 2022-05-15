// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	ll res = 0;
	if (n==0 || n==1) res = 1;
	else {
		vector<ll> dp(3);
		dp[0] = dp[1] = 1;
		rep3(i, 2, n+1) dp[i%3] = dp[(i+2)%3] + dp[(i+1)%3];
		res = dp[n%3];
	}
	cout << res << endl;
	return 0;
}
