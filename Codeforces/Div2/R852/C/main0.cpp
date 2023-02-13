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
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		set<int> st;
		rep(i, n) st.insert(a[i]);
		int li = 0, ri = n - 1;
		while (li <= ri) {
			int lval = *st.begin(), rval = *st.rbegin();
			if (a[li]==lval || a[li]==rval) {
				st.erase(a[li]);
				++li;
			}
			else if (a[ri]==lval || a[ri]==rval) {
				st.erase(a[ri]);
				--ri;
			}
			else break;
		}
		if (li > ri) cout << -1 << endl;
		else cout << (li+1) << ' ' << (ri+1) << endl;
	}
	return 0;
}
