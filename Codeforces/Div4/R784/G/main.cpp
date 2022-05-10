// 

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
		vector<string> g(n);
		rep(i, n) cin >> g[i];
		vector<pair<int, int>> stones;
		rep(i, n) rep(j, m) if (g[i][j] == '*') stones.emplace_back(i, j);
		sort(stones.rbegin(), stones.rend());
		int slen = stones.size();
		rep(i, slen) {
			int y = stones[i].first, x = stones[i].second;
			while (y+1 < n) {
				if (g[y+1][x] != '.') break;
				g[y+1][x] = '*';
				g[y][x] = '.';
				++y;
			}
		}
		rep(i, n) cout << g[i] << endl;
	}
	return 0;
}
