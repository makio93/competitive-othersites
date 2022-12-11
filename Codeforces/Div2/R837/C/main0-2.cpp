// 本番TLE2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

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
		unordered_map<int, int> acnt;
		bool ok = false;
		rep(i, n) if (a[i] > 1) {
			acnt[a[i]]++;
			if (acnt[a[i]] >= 2) {
				ok = true;
				break;
			}
		}
		if (ok) {
			cout << "YES" << endl;
			continue;
		}
		vector<int> b;
		for (const auto& pi : acnt) b.push_back(pi.first);
		sort(all(b));
		int m = b.size();
		if (m == 0) {
			cout << "NO" << endl;
			continue;
		}
		int rval = (int)(ceil(sqrt(b.back())));
		vector<bool> vals(rval+1);
		for (int i=2; i<=rval; ++i) {
			if (!vals[i]) {
				int cnt = 0;
				rep(j, m) if (b[j]%i == 0) ++cnt;
				if (cnt >= 2) {
					ok = true;
					break;
				}
			}
			for (int j=i*2; j<=rval; j+=i) vals[j] = true;
		}
		if (ok) {
			cout << "YES" << endl;
			continue;
		}
		int li = upper_bound(all(b), rval) - b.begin();
		rep3(i, li, m) {
			rep3(j, i+1, m) if (gcd(b[i], b[j]) > 1) {
				ok = true;
				break;
			}
			if (ok) break;
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
