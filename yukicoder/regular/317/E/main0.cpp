#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

const int INF = (int)(1e9);

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> a(q), b(q);
	rep(i, q) cin >> a[i] >> b[i];
	vector<pair<int, int>> ab(q);
	rep(i, q) ab[i] = { a[i], -b[i] };
	sort(all(ab));
	vector<int> blst(q);
	rep(i, q) blst[i] = -ab[i].second;
	vector<int> dp(q+1, INF);
	rep(i, q) *lower_bound(all(dp), blst[i]) = blst[i];
	int res = 0;
	rep(i, q+1) if (dp[i] < INF) res = max(res, i+1);
	cout << res << endl;
	return 0;
}
