#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番TLE

const ll mod = (ll)(1e9) + 7;

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	map<int, int> kprimes;
	ll kval = k;
	for (ll i=2; i*i<=kval; ++i) if (kval%i == 0) {
		kprimes[i] = 0;
		while (kval%i == 0) {
			kprimes[i]++;
			kval /= i;
		}
	}
	if (kval > 1) kprimes[kval] = 1;
	map<map<int, int>, ll> acnt;
	rep(i, n) {
		ll aval = a[i];
		map<int, int> aprimes;
		for (auto pi : kprimes) {
			aprimes[pi.first] = 0;
			while (aval%pi.first == 0) {
				aprimes[pi.first]++;
				aval /= pi.first;
			}
		}
		map<map<int, int>, ll> nacnt;
		for (auto pi : acnt) {
			auto nprimes = pi.first;
			for (auto pi2 : aprimes) nprimes[pi2.first] = min(kprimes[pi2.first], nprimes[pi2.first]+pi2.second);
			nacnt[nprimes] = (nacnt[nprimes] + pi.second) % mod;
		}
		for (auto pi : nacnt) acnt[pi.first] = (acnt[pi.first] + pi.second) % mod;
		acnt[aprimes] = (acnt[aprimes] + 1) % mod;
	}
	cout << acnt[kprimes] << endl;
	return 0;
}
