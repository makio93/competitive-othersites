// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	int t;
	cin >> t;
	rep(i1, t) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		int xsum = 0;
		rep(i, n) xsum ^= a[i];
		if (xsum == 0) {
			cout << "YES" << endl;
			continue;
		}
		vector<int> lsum(n+1), rsum(n+1);
		rep(i, n) lsum[i+1] = lsum[i] ^ a[i];
		repr(i, n) rsum[i] = rsum[i+1] ^ a[i];
		set<int> memo;
		bool ok = false;
		rep3(i, 1, n+1) {
			if (lsum[i] == 0) if (memo.find(rsum[i]) != memo.end()) ok = true;
			memo.insert(lsum[i]);
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
