#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番TLE

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
		multiset<int> vals;
		map<int, int> acnt;
		vals.insert(a[0]);
		acnt[a[0]]++;
		int res = 0;
		rep3(i, 1, n) {
			int ncnt = 0;
			if (acnt.find(a[i]) != acnt.end()) ncnt += acnt[a[i]];
			int lcnt = distance(vals.begin(), vals.lower_bound(a[i]));
			int rcnt = i - ncnt - lcnt;
			res += min(lcnt, rcnt);
			acnt[a[i]]++;
			vals.insert(a[i]);
		}
		cout << res << endl;
	}
	return 0;
}
