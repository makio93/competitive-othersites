// 本番TLE1

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = (int)(1e9);

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		ll w;
		cin >> n >> w;
		vector<ll> wi(n);
		rep(i, n) cin >> wi[i];
		vector<ll> fib(n);
		rep(i, n) {
			if (i == 0) fib[i] = 1;
			else if (i == 1) fib[i] = 2;
			else fib[i] = fib[i-2] + fib[i-1];
		}
		unordered_map<ll, ll> vals;
		ll res = 0;
		vals[0] = 0;
		repr(i, n) {
			auto pvals = vals;
			for (const auto& pi : pvals) if (pi.first+wi[i] <= w) {
				chmax(vals[pi.first+wi[i]], pi.second+fib[i]);
				res = max(res, pi.second+fib[i]);
			}
		}
		cout << res << endl;
	}
	return 0;
}
