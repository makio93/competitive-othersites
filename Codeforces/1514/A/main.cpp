#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int t;
	cin >> t;
	rep(i1, t) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		bool sq = true;
		for (int i=0; i<n; ++i) {
			int r = sqrt(a[i]);
			bool ok = false;
			while (r*r <= a[i]) {
				if (r*r == a[i]) ok = true;
				++r;
			}
			if (!ok) sq = false;
		}
		if (!sq) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

