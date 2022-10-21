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
		int li = 0, ri = n+1;
		while (ri-li > 1) {
			int ci = li + (ri-li) / 2, kcnt = 0;
			multiset<int> st;
			rep(i, n) if (a[i] <= ci) st.insert(a[i]);
			while (kcnt<ci && !st.empty() && *st.begin()<=ci-kcnt) {
				while (*st.rbegin() > ci-kcnt) st.erase(st.find(*st.rbegin()));
				st.erase(st.find(*st.rbegin()));
				if (!st.empty()) {
					int sval = *st.begin() + ci - kcnt;
					st.erase(st.begin());
					st.insert(sval);
				}
				++kcnt;
			}
			if (kcnt == ci) li = ci;
			else ri = ci;
		}
		cout << li << endl;
	}
	return 0;
}
