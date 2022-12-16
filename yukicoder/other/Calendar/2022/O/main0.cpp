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

const int INF = (int)(1e9);
const int VMAX = 300;

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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<unordered_map<int, mint>> vcnt(n+1);
	combination cb(VMAX*2+5);
	int mn = 0, mx = 0;
	vcnt[0][0] = 1;
	rep(i, n) {
		rep(j, b[i]+1) {
			int lval = 0, rval = j, add = -j;
			mint mval = 0;
			while (lval<=a[i] && rval<=b[i]) {
				mval += cb(a[i], lval) * cb(b[i], rval);
				++lval; ++rval;
			}
			for (const auto& pi : vcnt[i]) if (i+1<m || (pi.first+add>=mn&&pi.first+add<=mx)) {
				vcnt[i+1][pi.first+add] += pi.second * mval;
				mn = min(mn, pi.first+add);
				mx = max(mx, pi.first+add);
			}
		}
		rep3(j, 1, a[i]+1) {
			int lval = j, rval = 0, add = j;
			mint mval = 0;
			while (lval<=a[i] && rval<=b[i]) {
				mval += cb(a[i], lval) * cb(b[i], rval);
				++lval; ++rval;
			}
			for (const auto& pi : vcnt[i]) if (i+1<m || (pi.first+add>=mn&&pi.first+add<=mx)) {
				vcnt[i+1][pi.first+add] += pi.second * mval;
				mn = min(mn, pi.first+add);
				mx = max(mx, pi.first+add);
			}
		}
	}
	mint res = 1;
	rep(i, m) {
		if (i > n) break;
		mint val = 0;
		for (const auto& pi : vcnt[i]) {
			mint tval = pi.second;
			for (int j=i+m; j<=n; j+=m) {
				if (vcnt[j].find(pi.first) == vcnt[j].end()) {
					tval = 0;
					break;
				}
				tval *= vcnt[j][pi.first];
			}
			val += tval;
		}
		res *= val;
	}
	cout << res.val() << endl;
	return 0;
}
