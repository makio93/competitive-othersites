// TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n, q;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	cin >> q;
	rep(i, q) {
		int mi;
		cin >> mi;
		bool ok = false;
		rep(i1, (1<<n)) {
			int sum = 0;
			rep(j1, n) if ((i1>>j1)&1) {
				sum += a[j1];
				if (sum > mi) break;
			}
			if (sum == mi) {
				ok = true;
				break;
			}
		}
		if (ok) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
