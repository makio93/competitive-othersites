// 解説AC

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
		string s;
		cin >> s;
		int n = s.length();
		vector<int> qlst;
		int lcnt = n / 2, rcnt = n / 2;
		rep(i, n) {
			if (s[i] == '?') qlst.push_back(i);
			else if (s[i] == '(') --lcnt;
			else --rcnt;
		}
		int m = qlst.size();
		rep(i, m) {
			if (i < lcnt) s[qlst[i]] = '(';
			else s[qlst[i]] = ')';
		}
		bool ok = true;
		if (lcnt>0 && rcnt>0) {
			ok = false;
			swap(s[qlst[lcnt-1]], s[qlst[lcnt]]);
			int vcnt = 0;
			rep(i, n) {
				if (s[i] == '(') ++vcnt;
				else --vcnt;
				if (vcnt < 0) {
					ok = true;
					break;
				}
			}
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
