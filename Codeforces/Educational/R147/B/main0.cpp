// 

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
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		int l1 = n, r1 = -1;
		rep(i, n) if (a[i] != b[i]) {
			l1 = min(l1, i);
			r1 = max(r1, i);
		}
		int l2 = l1, r2 = r1;
		while (l2-1>=0 && b[l2-1]<=b[l2]) --l2;
		while (r2+1<n && b[r2+1]>=b[r2]) ++r2;
		cout << (l2+1) << ' ' << (r2+1) << endl;
	}
	return 0;
}
