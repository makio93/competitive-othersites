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
	int q0;
	cin >> q0;
	rep(i0, q0) {
		string t;
		int n;
		cin >> t >> n;
		int tlen = t.length();
		vector<string> s(n);
		rep(i, n) cin >> s[i];
		vector<pair<int, pair<int, int>>> dp(tlen+1, make_pair(INF, make_pair(-1, -1)));
		dp[0] = make_pair(0, make_pair(-1, -1));
		rep(i, tlen) rep(j, n) if (i+1-(int)(s[j].length())>=0 && t.substr(i+1-s[j].length(),s[j].length())==s[j]) {
			pair<int, int> mval = { INF, -1 };
			rep(j2, s[j].length()) if (dp[i-j2].first != INF) mval = min(mval, make_pair(dp[i-j2].first, i-j2));
			if (mval.first == INF) continue;
			dp[i+1] = min(dp[i+1], make_pair(mval.first+1, make_pair(mval.second, j)));
		}
		if (dp[tlen].first == INF) {
			cout << -1 << endl;
			continue;
		}
		vector<pair<int, int>> rlst;
		int pid = tlen;
		while (pid > 0) {
			rlst.emplace_back(pid-s[dp[pid].second.second].length()+1, dp[pid].second.second);
			pid = dp[pid].second.first;
		}
		reverse(all(rlst));
		int m = rlst.size();
		cout << m << endl;
		rep(i, m) cout << (rlst[i].second+1) << ' ' << (rlst[i].first) << endl;
	}
	return 0;
}
