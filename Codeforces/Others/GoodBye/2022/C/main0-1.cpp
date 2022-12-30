// 本番WA

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
		vector<ll> a(n);
		rep(i, n) cin >> a[i];
		sort(all(a));
		a.erase(unique(all(a)), a.end());
		if ((int)(a.size()) < n) {
			cout << "NO" << endl;
			continue;
		}
		vector<int> tcnt(2);
		rep(i, n) tcnt[a[i]%2]++;
		if (tcnt[0]>=2 && tcnt[1]>=2) {
			cout << "NO" << endl;
			continue;
		}
		bool ok = false;
		int sval = (tcnt[0]>=2 || (n==2&&tcnt[0]==1&&tcnt[1]==1)) ? 1 : 2, add = (n==2 && tcnt[0]==1 && tcnt[1]==1) ? 1 : 2;
		rep(i1, 200) {
			bool tok = true;
			rep(i, n) {
				rep3(j, i+1, n) if (gcd(a[i]+sval, a[j]+sval) > 1) {
					tok = false;
					break;
				}
				if (!tok) break;
			}
			if (tok) {
				ok = true;
				break;
			}
			sval += add;
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
