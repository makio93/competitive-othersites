// 学習0回目,自力AC1

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
	vector<int> s(n);
	rep(i, n) cin >> s[i];
	cin >> q;
	vector<int> t(q);
	rep(i, q) cin >> t[i];
	int res = 0;
	rep(i, q) {
		auto itr = lower_bound(all(s), t[i]);
		if (itr!=s.end() && *itr==t[i]) ++res;
	}
	cout << res << endl;
	return 0;
}
