// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n, q;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int sum = 0;
	rep(i, n) sum += a[i];
	sum = max(sum, 2000);
	vector<bool> dp(sum+1);
	dp[0] = true;
	rep(i, n) repr(j, sum-a[i]+1) if (dp[j]) dp[j+a[i]] = true;
	cin >> q;
	rep(i, q) {
		int mi;
		cin >> mi;
		if (dp[mi]) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
