#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

const int INF = (int)(1e9);

template<typename T>
struct BIT {
	int n;
	vector<T> d;
	BIT(int n=0) : n(n), d(n+1, INF) {}
	void add(int i, T x=1) {
		for (i++; i<=n; i+=i&-i) {
			d[i] = min(d[i], x);
		}
	}
	T query(int i) {
		T x = INF;
		for (i++; i; i-=i&-i) {
			x = min(d[i], x);
		}
		return x;
	}
};

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		pair<int, int> aval = { a[0], 0 }, bval = { b[0], 0 };
		BIT<int> alst(2*n+1);
		rep(i, n) alst.add(a[i], i);
		int res = INF;
		rep(i, n) res = min(res, i+alst.query(b[i]));
		cout << res << endl;
	}
	return 0;
}
