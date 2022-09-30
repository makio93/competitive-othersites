// 自力WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

const vector<vector<int>> tids = { { 1, 2 }, { 0, 3 } };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<string> s(2);
	rep(i, 2) cin >> s[i];
	int bcnt = 0;
	rep(i, 2) bcnt += count(all(s[i]), '1');
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(1<<4, vector<int>(2, INF)));
	queue<tuple<int, int, int>> que;
	auto toid = [&](int li) -> int {
		int rval = 0;
		if (li+1 < n) {
			rval |= (s[1][li+1]-'0') << 3;
			rval |= (s[0][li+1]-'0') << 2;
		}
		rval |= (s[1][li]-'0') << 1;
		rval |= (s[0][li]-'0');
		return rval;
	};
	dp[0][toid(0)][0] = 0;
	que.emplace(0, toid(0), 0);
	while (!que.empty()) {
		auto pi = que.front(); que.pop();
		int li = get<0>(pi), sid = get<1>(pi), vi = get<2>(pi), di = dp[li][sid][vi];
		if ((sid&(1<<(1-vi))) && (sid&(1<<(vi+2)))) {
			int nid1 = ((toid(li+1) & (~((1<<2)-1))) | (sid>>2)) ^ (1<<vi);
			if (dp[li+1][nid1][vi] > di+1) {
				dp[li+1][nid1][vi] = di+1;
				que.emplace(li+1, nid1, vi);
			}
			int nid2 = (sid^(1<<(vi+2))) ^ (1<<(1-vi));
			if (dp[li][nid2][1-vi] > di+1) {
				dp[li][nid2][1-vi] = di+1;
				que.emplace(li, nid2, 1-vi);
			}
		}
		else if (sid&(1<<(1-vi))) {
			int nid = sid ^ (1<<(1-vi));
			if (dp[li][nid][1-vi] > di) {
				dp[li][nid][1-vi] = di;
				que.emplace(li, nid, 1-vi);
			}
		}
		else if (sid&(1<<(vi+2))) {
			int nid = ((toid(li+1) & (~((1<<2)-1))) | (sid>>2)) ^ (1<<vi);
			if (dp[li+1][nid][vi] > di) {
				dp[li+1][nid][vi] = di;
				que.emplace(li+1, nid, vi);
			}
		}
		else if (li+1 < n) {
			int nid = (toid(li+1) & (~((1<<2)-1))) | (sid>>2);
			if (dp[li+1][nid][vi] > di) {
				dp[li+1][nid][vi] = di;
				que.emplace(li+1, nid, vi);
			}
		}
		else if (vi == 0) {
			if (dp[li][sid][1] > di) dp[li][sid][1] = di;
		}
	}
	int res = 0;
	rep(i, 1<<4) if (dp[n-1][i][1] != INF) res = max(res, dp[n-1][i][1]);
	cout << (bcnt-res) << endl;
	return 0;
}
