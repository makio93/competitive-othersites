// 本番WA

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
		vector<vector<int>> g(n);
		rep(i, n-1) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			g[xi].push_back(yi);
			g[yi].push_back(xi);
		}
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		vector<int> dist1(n, INF);
		queue<int> que;
		dist1[0] = 0;
		que.push(0);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			int di = dist1[vi];
			for (int ti : g[vi]) if (dist1[ti] == INF) {
				dist1[ti] = di+1;
				que.push(ti);
			}
		}
		pair<int, int> mval = { -1, -1 };
		rep(i, n) mval = max(mval, { dist1[i], i });
		int si = mval.second;
		vector<int> dist2(n, INF);
		que = queue<int>();
		dist2[si] = 0;
		que.push(si);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			int di = dist2[vi];
			for (int ti : g[vi]) if (dist2[ti] == INF) {
				dist2[ti] = di+1;
				que.push(ti);
			}
		}
		vector<int> dcnt(n);
		rep(i, n) dcnt[dist2[i]]++;
		int tval = 0;
		rep(i, n) tval = max(tval, dcnt[i]);
		int res = 1;
		while (tval > 1) {
			tval /= 2;
			++res;
		}
		cout << res << endl;
	}
	return 0;
}
