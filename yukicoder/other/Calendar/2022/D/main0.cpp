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

const ll mod = (ll)(1e9) + 7;
ll modpow(ll a, ll b) {
	ll p = 1, q = a;
	rep(i, 63) {
		if (b & (1LL<<i)) p = p * q % mod;
		q = q * q % mod;
	}
	return p;
}
ll f(ll n) { return (modpow(2, n) - 1 + mod) % mod; }

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<pair<int, int>> slst;
	rep(i, n) if (i+1>=n || s[i+1]!=s[i]) slst.emplace_back(i+1, s[i]-'A');
	int nid = slst[0].first, m = slst.size(), pid = slst[0].second;
	ll res = 0;
	if (m == 1) { if (pid != 0) res = (res + f(n)) % mod; }
	else {
		rep3(i, 1, m) {
			if (i == m-1) {
				if (slst[i].second == 0) res = (res + f(nid)) % mod;
				else if (pid == 0) res = (res + f(nid) * 2 + f(slst[i].first-nid)) % mod;
				else res = (res + f(nid) + f(slst[i].first-nid)) % mod;
			}
			else {
				if (i+1 == m-1) {
					if (slst[i+1].second == 0) {
						if (pid == 0) res = (res + f(nid) * 2 + f(slst[i].first-nid)) % mod;
						else res = (res + f(nid) + f(slst[i].first-nid)) % mod;
					}
					else {
						if (pid == 0) {
							if (abs(slst[i].first-(slst[i+1].first-slst[i].first)) <= abs(nid-(slst[i+1].first-nid))) 
								res = (res + f(nid)+f(slst[i+1].first-slst[i].first)+f(slst[i].first)) % mod;
							else res = (res + f(slst[i].first-nid)+f(nid)*2+f(slst[i+1].first-nid)) % mod;
						}
						else {
							if (abs(slst[i].first-(slst[i+1].first-slst[i].first)) <= abs(nid-(slst[i+1].first-nid))) 
								res = (res + f(nid)+f(slst[i].first)*2+f(slst[i+1].first-slst[i].first)) % mod;
							else res = (res + f(slst[i].first-nid)+f(slst[i+1].first-nid)+f(nid)) % mod;
						}
					}
				}
				else {
					if (slst[i+1].second == pid) res = (res + f(nid)*2+f(slst[i].first-nid)) % mod;
					else res = (res + f(nid)+f(slst[i].first-nid)) % mod;
				}
				++i;
			}
			nid = slst[i].first, pid = slst[i].second;
		}
	}
	cout << res << endl;
	return 0;
}
