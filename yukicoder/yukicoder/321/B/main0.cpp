#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番TLE

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	map<ll, int> avals;
	rep(i, n) avals[a[i]]++;
	int alen = avals.size();
	map<ll, int> gvals;
	for (auto pi : avals) {
		for (auto itr=gvals.begin(); itr!=gvals.end(); ++itr) {
			ll gval = gcd(itr->first, pi.first);
			if (gvals.find(gval) == gvals.end()) gvals[gval] = itr->second + pi.second;
			else gvals[gval] = max(gvals[gval], itr->second+pi.second);
		}
		if (gvals.find(pi.first) == gvals.end()) gvals[pi.first] = pi.second;
		else gvals[pi.first] = max(gvals[pi.first], pi.second);
	}
	vector<ll> mvals(n+1);
	for (auto pi : gvals) mvals[pi.second] = max(mvals[pi.second], pi.first);
	repr(i, n) mvals[i] = max(mvals[i], mvals[i+1]);
	rep3r(i, 1, n+1) cout << mvals[i] << endl;
	return 0;
}
