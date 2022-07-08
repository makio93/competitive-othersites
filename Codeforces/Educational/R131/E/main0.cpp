// 本番作成,解答不能

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
		int n, m;
		string s, t;
		cin >> n >> m >> s >> t;
		vector<int> llst, rlst;
		bool ok = true;
		int sid = 0;
		rep(i, m) {
			while (sid<n && s[sid]!=t[i]) ++sid;
			if (sid >= n) {
				ok = false;
				break;
			}
			llst.push_back(sid);
			++sid;
		}
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		sid = n-1;
		repr(i, m) {
			while (sid>=0 && s[sid]!=t[i]) --sid;
			if (sid < 0) {
				ok = false;
				break;
			}
			rlst.push_back(sid);
			--sid;
		}
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		reverse(all(rlst));
		vector<pair<int, int>> glst;
		// 解答不能
		int res = n;
	}
	return 0;
}
