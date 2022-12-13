// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

const int INF = (int)(1e9);
const int MAX = (int)(1e7);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<int> sie(MAX+1);
	iota(all(sie), 0);
	for (int i=2; i*i<=MAX; ++i) if (sie[i] == i) for (int j=i*i; j<=MAX; j+=i) sie[j] = min(sie[j], i);
	rep(i, n) {
		ll gi = gcd(x[i], y[i]);
		if (gi != 1) {
			cout << 0 << endl;
			continue;
		}
		int sub = y[i] - x[i];
		if (sub == 1) {
			cout << -1 << endl;
			continue;
		}
		int res = INF, tmp = sub;
		while (tmp > 1) {
			int pval = sie[tmp];
			res = min(res, pval-(x[i]%pval));
			while (tmp%pval == 0) tmp /= pval;
		}
		cout << res << endl;
	}
	return 0;
}
