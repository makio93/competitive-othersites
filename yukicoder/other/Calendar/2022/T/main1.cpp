// 解説AC

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
		vector<ll> wi(n), fib(n);
		rep(i, n) cin >> wi[i];
		rep(i, n) {
			if (i == 0) fib[i] = 1;
			else if (i == 1) fib[i] = 2;
			else fib[i] = fib[i-2] + fib[i-1];
		}
		map<ll, ll, greater<ll>> vals;
		vals[0] = 0;
		repr(i, n) {
			auto nvals = vals;
			for (const auto& pi : vals) if (pi.second+wi[i] <= w) {
				if (nvals.find(pi.first+fib[i]) == nvals.end()) nvals[pi.first+fib[i]] = pi.second+wi[i];
				else chmin(nvals[pi.first+fib[i]], pi.second+wi[i]);
			}
			if ((int)(nvals.size()) > 2) nvals.erase(next(nvals.begin(), 2), nvals.end());
			swap(nvals, vals);
		}
		cout << vals.begin()->first << endl;
	}
	return 0;
}
