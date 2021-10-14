#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

const vector<string> tar = { "00", "25", "50", "75" };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		string n;
		cin >> n;
		int len = n.length(), res = (int)(1e9);
		rep(i1, 4) {
			int rid = -1, lid = -1;
			repr(i, len) if (n[i] == tar[i1][1]) {
				rid = i;
				break;
			}
			if (rid == -1) continue;
			repr(i, rid) if (n[i] == tar[i1][0]) {
				lid = i;
				break;
			}
			if (lid == -1) continue;
			res = min(res, len-lid-2);
		}
		cout << res << endl;
	}
	return 0;
}
