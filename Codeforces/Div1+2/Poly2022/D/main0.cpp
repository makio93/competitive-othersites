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
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		rep(i, n) rep(j, m) cin >> a[i][j];
		int asum = 0;
		rep(i, n) asum += accumulate(all(a[i]), 0);
		if (asum%n != 0) {
			cout << -1 << endl;
			continue;
		}
		int tar = asum / n;
		unordered_set<int> uids, dids;
		vector<int> avals(n);
		rep(i, n) {
			avals[i] = accumulate(all(a[i]), 0);
			if (avals[i] > tar) uids.insert(i);
			else if (avals[i] < tar) dids.insert(i);
		}
		vector<tuple<int, int, int>> res;
		rep(i, m) {
			if (uids.empty()) break;
			vector<int> tui, tdi;
			rep(j, n) if (uids.find(j)!=uids.end() && a[j][i]==1) tui.push_back(j);
			rep(j, n) if (dids.find(j)!=dids.end() && a[j][i]==0) tdi.push_back(j);
			int tlen = (int)min(tui.size(), tdi.size());
			rep(j, tlen) {
				res.emplace_back(tui[j]+1, tdi[j]+1, i+1);
				swap(a[tui[j]][i], a[tdi[j]][i]);
				avals[tui[j]]--;
				avals[tdi[j]]++;
				if (avals[tui[j]] == tar) uids.erase(tui[j]);
				if (avals[tdi[j]] == tar) dids.erase(tdi[j]);
			}
		}
		int k = res.size();
		cout << k << endl;
		rep(i, k) cout << get<0>(res[i]) << ' ' << get<1>(res[i]) << ' ' << get<2>(res[i]) << endl;
	}
	return 0;
}
