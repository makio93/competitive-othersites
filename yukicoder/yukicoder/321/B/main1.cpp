#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	map<int, int> avals;
	rep(i, n) avals[a[i]]++;
	int mval = avals.rbegin()->first;
	vector<int> gcnt(mval+1);
	for (auto pi : avals) {
		for (int i=1; i*i<=pi.first; ++i) if (pi.first%i == 0) {
			gcnt[i] += pi.second;
			if (i != pi.first/i) gcnt[pi.first/i] += pi.second;
		}
	}
	vector<int> mvals(n+1);
	rep3(i, 1, mval+1) mvals[gcnt[i]] = max(mvals[gcnt[i]], i);
	repr(i, n) mvals[i] = max(mvals[i], mvals[i+1]);
	rep3r(i, 1, n+1) cout << mvals[i] << endl;
	return 0;
}
