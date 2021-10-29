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
		string s;
		cin >> s;
		int n = s.length();
		if (s[0] != s[n-1]) {
			int lcnt = 0, rcnt = 0;
			rep(i, n) {
				if (s[i] == s[0]) ++lcnt;
				else break;
			}
			repr(i, n) {
				if (s[i] == s[n-1]) ++rcnt;
				else break;
			}
			if (min(lcnt, rcnt) > 1) {
				if (s[0] == 'a') s[0] = 'b';
				else s[0] = 'a';
			}
			else {
				if (lcnt <= rcnt) {
					rep(i, lcnt) {
						if (s[i] == 'a') s[i] = 'b';
						else s[i] = 'a';
					}
				}
				else {
					rep(i, rcnt) {
						if (s[n-1-i] == 'a') s[n-1-i] = 'b';
						else s[n-1-i] = 'a';
					}
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
