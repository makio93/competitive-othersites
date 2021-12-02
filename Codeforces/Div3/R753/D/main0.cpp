#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

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
		string s;
		cin >> s;
		vector<int> rvals, bvals;
		rep(i, n) {
			if (s[i] == 'R') rvals.push_back(a[i]);
			else bvals.push_back(a[i]);
		}
		bool res = true;
		if (!rvals.empty()) {
			sort(rvals.rbegin(), rvals.rend());
			if (rvals[0] > n) res = false;
			int rcnt = 0;
			for (int ri : rvals) {
				++rcnt;
				if (n-ri+1 < rcnt) res = false;
			}
		}
		if (!bvals.empty()) {
			sort(all(bvals));
			if (bvals[0] < 1) res = false;
			int bcnt = 0;
			for (int bi : bvals) {
				++bcnt;
				if (bi < bcnt) res = false;
			}
		}
		cout << (res ? "YES" : "NO") << endl;
	}
	return 0;
}
