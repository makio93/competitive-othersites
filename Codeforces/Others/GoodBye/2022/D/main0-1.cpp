// 本番WA1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

struct UnionFind {
	vector<int> d;
	UnionFind(int n=0) : d(n, -1) {}
	int find(int x) {
		if (d[x] < 0) return x;
		return (d[x] = find(d[x]));
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		if (d[x] > d[y]) swap(x, y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	bool same(int x, int y) { return (find(x) == find(y)); }
	int size(int x) { return -d[find(x)]; }
};

const ll mod = 998244353LL;
struct mint {
	ll x;
	mint(ll x=0) : x((x%mod+mod)%mod) {}
	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod-a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
	mint operator+(const mint a) const { return mint(*this) += a;}
	mint operator-(const mint a) const { return mint(*this) -= a;}
	mint operator*(const mint a) const { return mint(*this) *= a;}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if (t&1) a *= *this;
		return a;
	}
	mint inv() const { return pow(mod-2);}
	mint& operator/=(const mint a) { return *this *= a.inv();}
	mint operator/(const mint a) const { return mint(*this) /= a;}
};
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		rep(i, n) {
			cin >> a[i];
			a[i]--;
		}
		rep(i, n) {
			cin >> b[i];
			b[i]--;
		}
		vector<int> vcnt(n);
		rep(i, n) vcnt[a[i]]++;
		rep(i, n) vcnt[b[i]]++;
		bool ok = true;
		rep(i, n) if (vcnt[i] != 2) ok = false;
		if (!ok) {
			cout << 0 << endl;
			continue;
		}
		vector<vector<int>> ids(n);
		rep(i, n) {
			ids[a[i]].push_back(i);
			ids[b[i]].push_back(i);
		}
		UnionFind d(n);
		rep(i, n) d.unite(ids[i][0], ids[i][1]);
		vector<int> glst, slst;
		rep(i, n) glst.push_back(d.find(i));
		sort(all(glst));
		glst.erase(unique(all(glst)), glst.end());
		int glen = glst.size();
		rep(i, glen) slst.push_back(d.size(glst[i]));
		mint res = 1;
		combination cb(n+1);
		rep(i, glen) {
			if (slst[i] == 1) res *= n;
			else res *= cb.fact[slst[i]];
		}
		cout << res.x << endl;
	}
	return 0;
}
