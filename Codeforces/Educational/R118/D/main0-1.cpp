#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

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
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		map<int, int> acnt;
		rep(i, n) acnt[a[i]]++;
		vector<mint> sum, ccnt;
		mint add = 0;
		if (acnt.find(1) != acnt.end()) add = mint(2).pow(acnt[1]) - 1;
		rep(i, n+1) {
			if (acnt.find(i) == acnt.end()) break;
			if (i == 0) ccnt.push_back(mint(2).pow(acnt[i])-1);
			else ccnt.push_back(ccnt[i-1]*(mint(2).pow(acnt[i])-1));
			sum.push_back(ccnt[i]);
			if (acnt.find(i+2) != acnt.end()) {
				sum[i] = (sum[i] + ccnt[i] * (mint(2).pow(acnt[i+2])-1));
			}
		}
		mint res = add;
		rep(i, (int)(sum.size())) res += sum[i];
		cout << res << endl;
	}
	return 0;
}
