// 本番WA

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

const ll mod = 998244353LL;
using mint = modint998244353;
struct combination {
	vector<mint> fact, ifact;
	combination(int n) : fact(n+1), ifact(n+1) {
		fact[0] = 1;
		for (int i=1; i<=n; ++i) fact[i] = fact[i-1] * i;
		ifact[n] = fact[n].inv();
		for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i;
	}
	mint operator()(int n, int k) {
		if (k<0 || k>n) return 0;
		return (fact[n] * ifact[k] * ifact[n-k]);
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	combination cb(n+3);
	vector<int> l(q), r(q);
	rep(i, q) {
		cin >> l[i] >> r[i];
		l[i]--;
	}
	vector<int> ids;
	ids.push_back(0);
	ids.push_back((n+1)/2*2);
	rep(i, q) {
		ids.push_back(l[i]);
		ids.push_back(r[i]);
	}
	sort(all(ids));
	ids.erase(unique(all(ids)), ids.end());
	mint res = 1;
	int m = ids.size();
	bool zero = false;
	rep(i, m-1) {
		if (i<m-2 && (ids[i+1]-ids[i])%2!=0) {
			zero = true;
			break;
		}
		int len = ids[i+1] - ids[i];
		mint val = cb(len, len/2) / (len/2+1);
		res *= val;
	}
	if (zero) {
		cout << 0 << endl;
		return 0;
	}
	res *= cb.fact[n/2];
	res *= cb.fact[(n+1)/2];
	cout << res.val() << endl;
	return 0;
}
