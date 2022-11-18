// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, p;
		cin >> n >> p;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		set<int> ast;
		rep(i, n) ast.insert(a[i]);
		if ((int)(ast.size()) == p) {
			cout << 0 << endl;
			continue;
		}
		int rval = -1, lval = p;
		repr(i, p) if (ast.find(i) == ast.end()) {
			rval = i;
			break;
		}
		rep(i, p) if (ast.find(i) == ast.end()) {
			lval = i;
			break;
		}
		if (lval >= a[n-1]) {
			cout << (rval-a[n-1]) << endl;
			continue;
		}
		int res = p - a[n-1], pa = a[n-1];
		a[n-1] = 0;
		ast.insert(0);
		int mid = n-1;
		repr(i, n-1) {
			mid = i;
			if (a[i]+1 < p) {
				a[i]++;
				ast.insert(a[i]);
				break;
			}
			a[i] = 0;
		}
		if (mid==0 && a[mid]==0) ast.insert(1);
		int nval = -1;
		repr(i, pa) if (ast.find(i) == ast.end()) {
			nval = i;
			break;
		}
		if (nval == -1) {
			cout << res << endl;
			continue;
		}
		res += nval;
		cout << res << endl;
	}
	return 0;
}
